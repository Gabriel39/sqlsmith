#include "doris.hh"
#include "config.h"
#include <iostream>
#include <string>
#include <mysql/mysql.h>

#ifndef HAVE_BOOST_REGEX

#include <regex>

#else
#include <boost/regex.hpp>
using boost::regex;
using boost::smatch;
using boost::regex_match;
#endif

using namespace std;

static regex e_timeout("ERROR:  canceling statement due to statement timeout(\n|.)*");
static regex e_syntax("ERROR:  syntax error at or near(\n|.)*");

doris_connection::doris_connection(std::string &conninfo) {
    _my_conn = mysql_init(nullptr);

    if (nullptr == _my_conn) {
        throw std::runtime_error("mysql init failed.");
    }
}

void doris_connection::q(const char *query) {
}

doris_connection::~doris_connection() {
    if (_my_result) {
        mysql_free_result(_my_result);
        _my_result = nullptr;
    }

    if (_my_conn) {
        mysql_close(_my_conn);
        _my_conn = nullptr;
    }
}

schema_doris::schema_doris(std::string &conninfo, bool no_catalog) : doris_connection(conninfo) {
    // TODO: make config
    std::string host = "127.0.0.1";
    std::string user = "root";
    std::string passwd = "";
    std::string db = "";
    std::string port = "9035";
    if (nullptr == mysql_real_connect(_my_conn, host.c_str(), user.c_str(),
                                      passwd.c_str(), db.c_str(),
                                      atoi(_my_param.port.c_str()), nullptr,
                                      _my_param.client_flag)) {
        cerr << "connect Mysql: "
                     << "Host: " << _my_param.host << " user: " << _my_param.user
                     << " passwd: " << _my_param.passwd << " db: " << _my_param.db
                     << " port: " << _my_param.port << endl;

        return;
    }

    int sql_result;

    // TODO: check more information

    cerr << "Loading tables..." << endl;
    std::string load_tables_query = "select table_name, table_schema, table_type from information_schema.tables";

    sql_result = mysql_query(_my_conn, load_tables_query.c_str());

    if (0 != sql_result) {
        cerr << "Load tables failed. query =" << load_tables_query;
        return;
    }

    // clean the last query result
    if (_my_result) {
        mysql_free_result(_my_result);
    }

    // use store result because mysql table is small, can load in memory avoid of many RPC
    _my_result = mysql_store_result(_my_conn);

    if (nullptr == _my_result) {
        cerr << "mysql store result failed." << endl;
        return;
    }

    int field_num = mysql_num_fields(_my_result);

    char** data = nullptr;
    unsigned long* length = nullptr;

    *buf = mysql_fetch_row(_my_result);
    *lengths = mysql_fetch_lengths(_my_result);

    cerr << "done." << endl;

    c.disconnect();
#endif
    generate_indexes();
}

