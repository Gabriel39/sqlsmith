#include <cstdlib>
#include <numeric>
#include <algorithm>

#include "random.hh"
#include "relmodel.hh"
#include "grammar.hh"
#include "schema.hh"

using namespace std;

std::ostream& operator<<(std::ostream& s, prod& p)
{
  p.out(s); return s;
}

shared_ptr<table_ref> table_ref::factory(scope &s) {
  shared_ptr<table_ref> r;
  if (random()%4)
    r = make_shared<table_or_query_name>(s);
  else if (random()%2)
    r = make_shared<joined_table>(s);
  else
    r = make_shared<table_subquery>(s);
  return r;
}

int table_or_query_name::sequence = 0;
table_or_query_name::table_or_query_name(scope &s) {
  t = random_pick<named_relation*>(s.tables);
  ostringstream o;
  o << "rel" << sequence++;
  alias = o.str();
}

void table_or_query_name::out(std::ostream &out) {
  out << t->ident() << " as " << ident();
}

int table_subquery::instances;

table_subquery::table_subquery(scope &s) {
  query = new query_spec(s);
  t = new named_relation();
  t->columns = query->sl.derived_table.columns;
  ostringstream r;
  r << "subq_" << instances++;
  t->name = r.str();
}

table_subquery::~table_subquery() {
  delete query;
  delete t;
}

joined_table::joined_table(scope &s) {
 retry:
  lhs = table_ref::factory(s);
  rhs = table_ref::factory(s);
  while (lhs->t == rhs->t) {
    rhs = table_ref::factory(s);
  }

  condition = "";

  column c1 = random_pick<column>(lhs->t->columns);
  if (c1.type == "ARRAY"
      || c1.type == "anyarray") {
    goto retry;
  }

  for (auto c2 : rhs->t->columns) {
    if (c1.type == c2.type) {
      condition +=
	lhs->ident() + "." + c1.name + " = " + rhs->ident() + "." + c2.name + " ";
      break;
    }
  }
  if (condition == "") {
    goto retry;
  }

  if (random()&1) {
    type = "inner";
    t = lhs->t;
    alias = lhs->ident();
  } else if (random()&1) {
    type = "left";
    t = lhs->t;
    alias = lhs->ident();
  } else {
    type = "right";
    t = rhs->t;
    alias = rhs->ident();
  }
}

void joined_table::out(std::ostream &out) {
  out << *lhs << " " << type << " join "
      << *rhs << " on (" << condition << ")";
}

void table_subquery::out(std::ostream &out) {
  out << "(" << *query << ") as " << t->name;
}

void from_clause::out(std::ostream &out) {
  if (! reflist.size())
    return;
  out << "\n    from " << *reflist[0];
}

from_clause::from_clause(scope &s) {
  reflist.push_back(table_ref::factory(s));
}


shared_ptr<value_expr> value_expr::factory(query_spec *q)
{
  shared_ptr<value_expr> r;

  if (0==random()%42)
    r = make_shared<const_expr>();
  else
    r = make_shared<column_reference>(q);

  if (! r->type.size())
    throw logic_error("generated expr with unknown type");
  return r;
}

column_reference::column_reference(query_spec *q)
{
  shared_ptr<table_ref> ref = random_pick<shared_ptr<table_ref> >(q->fc.reflist);
  relation *r = ref->t;
  reference += ref->ident() + ".";
  column c = random_pick<column>(r->columns);
  type = c.type;
  reference += c.name;
}

shared_ptr<bool_expr> bool_expr::factory(struct query_spec *q)
{
  if(random()%2)
    return make_shared<comparison_op>(q);
  else if (random()%2)
    return make_shared<bool_term>(q);
  else if (random()%2)
    return make_shared<truth_value>(q);
  else
    return make_shared<null_predicate>(q);
}

comparison_op::comparison_op(struct query_spec *q) : bool_expr(q)
{
  retry:
  lhs = value_expr::factory(q);
  rhs = value_expr::factory(q);

  auto op_iter =
    schema.find_operator(lhs->type, rhs->type, string("boolean"));

  if (op_iter == schema.index.end())
    goto retry;

  oper = &op_iter->second;
}

select_list::select_list(query_spec *q)
{
  do {
    shared_ptr<value_expr> e = value_expr::factory(q);
    value_exprs.push_back(e);
    ostringstream name;
    name << "c" << columns++;
    derived_table.columns.push_back(column(name.str(), e->type));
  } while (random()%7);
}

void select_list::out(std::ostream &out)
{
  int i = 0;
  for (auto expr = value_exprs.begin(); expr != value_exprs.end(); expr++) {
    out << **expr << " as " << derived_table.columns[i].name;
    i++;
    if (expr+1 != value_exprs.end())
      out << ", ";
  }
}

void query_spec::out(std::ostream &out) {
  out << "select " << set_quantifier << " "
      << sl << " " << fc << " where " << *search << " "
      << limit_clause;
}

query_spec::query_spec(scope &s) : fc(s), sl(this) {

  vector<column> &cols = sl.derived_table.columns;

  if (!count_if(cols.begin(), cols.end(),
		[] (column c) { return c.type == "anyarray"; })) {
    set_quantifier = (random() % 5) ? "" : "distinct ";
  }

  search = bool_expr::factory(this);

  if (0 == random()%3) {
    ostringstream cons;
    cons << " fetch first " << random()%100 + random()%100 << " rows only ";
    limit_clause = cons.str();
  }
}

long prepare_stmt::seq;
