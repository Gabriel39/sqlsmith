# Install script for directory: /var/local/incubator-doris/thirdparty/src/mysql-server-mysql-5.7.18/include

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/var/local/incubator-doris/thirdparty/installed/mysql")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "RelWithDebInfo")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "0")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/var/local/ldb-toolchain/bin/objdump")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE FILE FILES "/var/local/incubator-doris/thirdparty/src/mysql-server-mysql-5.7.18/include/../libbinlogevents/export/binary_log_types.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE FILE FILES
    "/var/local/incubator-doris/thirdparty/src/mysql-server-mysql-5.7.18/include/mysql.h"
    "/var/local/incubator-doris/thirdparty/src/mysql-server-mysql-5.7.18/include/mysql_com.h"
    "/var/local/incubator-doris/thirdparty/src/mysql-server-mysql-5.7.18/include/my_command.h"
    "/var/local/incubator-doris/thirdparty/src/mysql-server-mysql-5.7.18/include/mysql_time.h"
    "/var/local/incubator-doris/thirdparty/src/mysql-server-mysql-5.7.18/include/my_list.h"
    "/var/local/incubator-doris/thirdparty/src/mysql-server-mysql-5.7.18/include/my_alloc.h"
    "/var/local/incubator-doris/thirdparty/src/mysql-server-mysql-5.7.18/include/typelib.h"
    "/var/local/incubator-doris/thirdparty/src/mysql-server-mysql-5.7.18/include/mysql/plugin.h"
    "/var/local/incubator-doris/thirdparty/src/mysql-server-mysql-5.7.18/include/mysql/plugin_audit.h"
    "/var/local/incubator-doris/thirdparty/src/mysql-server-mysql-5.7.18/include/mysql/plugin_ftparser.h"
    "/var/local/incubator-doris/thirdparty/src/mysql-server-mysql-5.7.18/include/mysql/plugin_validate_password.h"
    "/var/local/incubator-doris/thirdparty/src/mysql-server-mysql-5.7.18/include/mysql/plugin_keyring.h"
    "/var/local/incubator-doris/thirdparty/src/mysql-server-mysql-5.7.18/include/mysql/plugin_group_replication.h"
    "/var/local/incubator-doris/thirdparty/src/mysql-server-mysql-5.7.18/include/my_dbug.h"
    "/var/local/incubator-doris/thirdparty/src/mysql-server-mysql-5.7.18/include/m_string.h"
    "/var/local/incubator-doris/thirdparty/src/mysql-server-mysql-5.7.18/include/my_sys.h"
    "/var/local/incubator-doris/thirdparty/src/mysql-server-mysql-5.7.18/include/my_xml.h"
    "/var/local/incubator-doris/thirdparty/src/mysql-server-mysql-5.7.18/include/mysql_embed.h"
    "/var/local/incubator-doris/thirdparty/src/mysql-server-mysql-5.7.18/include/my_thread.h"
    "/var/local/incubator-doris/thirdparty/src/mysql-server-mysql-5.7.18/include/my_thread_local.h"
    "/var/local/incubator-doris/thirdparty/src/mysql-server-mysql-5.7.18/include/decimal.h"
    "/var/local/incubator-doris/thirdparty/src/mysql-server-mysql-5.7.18/include/errmsg.h"
    "/var/local/incubator-doris/thirdparty/src/mysql-server-mysql-5.7.18/include/my_global.h"
    "/var/local/incubator-doris/thirdparty/src/mysql-server-mysql-5.7.18/include/my_getopt.h"
    "/var/local/incubator-doris/thirdparty/src/mysql-server-mysql-5.7.18/include/sslopt-longopts.h"
    "/var/local/incubator-doris/thirdparty/src/mysql-server-mysql-5.7.18/include/my_dir.h"
    "/var/local/incubator-doris/thirdparty/src/mysql-server-mysql-5.7.18/include/sslopt-vars.h"
    "/var/local/incubator-doris/thirdparty/src/mysql-server-mysql-5.7.18/include/sslopt-case.h"
    "/var/local/incubator-doris/thirdparty/src/mysql-server-mysql-5.7.18/include/sql_common.h"
    "/var/local/incubator-doris/thirdparty/src/mysql-server-mysql-5.7.18/include/keycache.h"
    "/var/local/incubator-doris/thirdparty/src/mysql-server-mysql-5.7.18/include/m_ctype.h"
    "/var/local/incubator-doris/thirdparty/src/mysql-server-mysql-5.7.18/include/my_compiler.h"
    "/var/local/incubator-doris/thirdparty/src/mysql-server-mysql-5.7.18/include/mysql_com_server.h"
    "/var/local/incubator-doris/thirdparty/src/mysql-server-mysql-5.7.18/include/my_byteorder.h"
    "/var/local/incubator-doris/thirdparty/src/mysql-server-mysql-5.7.18/include/byte_order_generic.h"
    "/var/local/incubator-doris/thirdparty/src/mysql-server-mysql-5.7.18/include/byte_order_generic_x86.h"
    "/var/local/incubator-doris/thirdparty/src/mysql-server-mysql-5.7.18/include/little_endian.h"
    "/var/local/incubator-doris/thirdparty/src/mysql-server-mysql-5.7.18/include/big_endian.h"
    "/var/local/incubator-doris/thirdparty/src/mysql-server-mysql-5.7.18/include/thr_cond.h"
    "/var/local/incubator-doris/thirdparty/src/mysql-server-mysql-5.7.18/include/thr_mutex.h"
    "/var/local/incubator-doris/thirdparty/src/mysql-server-mysql-5.7.18/include/thr_rwlock.h"
    "/var/local/incubator-doris/thirdparty/src/mysql-server-mysql-5.7.18/doris_build/include/mysql_version.h"
    "/var/local/incubator-doris/thirdparty/src/mysql-server-mysql-5.7.18/doris_build/include/my_config.h"
    "/var/local/incubator-doris/thirdparty/src/mysql-server-mysql-5.7.18/doris_build/include/mysqld_ername.h"
    "/var/local/incubator-doris/thirdparty/src/mysql-server-mysql-5.7.18/doris_build/include/mysqld_error.h"
    "/var/local/incubator-doris/thirdparty/src/mysql-server-mysql-5.7.18/doris_build/include/sql_state.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/mysql" TYPE DIRECTORY FILES "/var/local/incubator-doris/thirdparty/src/mysql-server-mysql-5.7.18/include/mysql/" REGEX "/[^/]*\\.h$" REGEX "/psi\\_abi[^/]*$" EXCLUDE)
endif()

