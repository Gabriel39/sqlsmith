/// @file
/// @brief schema and dut classes for Doris

#ifndef DORIS_HH
#define DORIS_HH

#include "dut.hh"
#include "relmodel.hh"
#include "schema.hh"
#include <mysql/mysql.h>
#define __DorisMysql MYSQL
#define __DorisMysqlRes MYSQL_RES

struct doris_connection {
    __DorisMysql* _my_conn;
    __DorisMysqlRes* _my_result;

    void q(const char *query);
    doris_connection(std::string &conninfo);
    ~doris_connection();
};


struct schema_doris : public schema, doris_connection {
  pqxx::connection c;
  map<OID, pg_type*> oid2type;
  map<string, pg_type*> name2type;

  virtual std::string quote_name(const std::string &id) {
    return c.quote_name(id);
  }
    schema_doris(std::string &conninfo, bool no_catalog);
};

struct dut_doris : dut_base, doris_connection {
  pqxx::connection c;
  virtual void test(const std::string &stmt);
  dut_pqxx(std::string conninfo);
};

#endif
