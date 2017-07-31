#include <getopt.h>
#include <unistd.h>
#include <string>
#include "spkgConfig.h"

#ifndef SPKGGETOPTS_H
#define SPKGGETOPTS_H

using namespace std;

typedef enum
{
      SPKG_HELP,
      SPKG_INITDB,
      SPKG_PACK,
      SPKG_EXTRACT,
      SPKG_INSTALL,
      SPKG_REMOVE,
      SPKG_UPDATE,
      SPKG_REPLACE,
      SPKG_QUERY,
      SPKG_SHOW,
} spkg_command_t;

#define SPKG_HELP_OPTION            "help"
#define SPKG_HELP_SHORT_OPTION      'h'
#define SPKG_INITDB_OPTION          "initdb"
#define SPKG_INITDB_SHORT_OPTION    'I'
#define SPKG_PACK_OPTION            "pack"
#define SPKG_PACK_SHORT_OPTION      'p'
#define SPKG_EXTRACT_OPTION         "extract"
#define SPKG_EXTRACT_SHORT_OPTION   'e'
#define SPKG_INSTALL_OPTION         "install"
#define SPKG_INSTALL_SHORT_OPTION   'i'
#define SPKG_REMOVE_OPTION          "remove"
#define SPKG_REMOVE_SHORT_OPTION    'r'
#define SPKG_UPDATE_OPTION          "update"
#define SPKG_UPDATE_SHORT_OPTION    'u'
#define SPKG_REPLACE_OPTION         "replace"
#define SPKG_REPLACE_SHORT_OPTION   'R'
#define SPKG_QUERY_OPTION           "query"
#define SPKG_QUERY_SHORT_OPTION     'q'
#define SPKG_SHOW_OPTION            "show"
#define SPKG_SHOW_SHORT_OPTION      's'
#define SPKG_SHORT_OPTIONS          "hIp:e:i:r:u:R:q:s:"

#define SPKG_DEFAULT_ROOT       "/"
#define SPKG_CHECK_RUN_DEPS       SPKG_YES
#define SPKG_CHECK_RUN_CONFLICTS  SPKG_YES
#define SPKG_CHECK_RUN_SUGGESTS   SPKG_YES
#define SPKG_RUN_PKG_SCRIPT       SPKG_YES
#define SPKG_RUN_FORCE_FLAG       SPKG_YES
#define SPKG_RUN_VERBOSE_MODE     SPKG_NO
#define SPKG_RUN_SILENT_MODE      SPKG_NO

class spkgGetOpts {
      public:
            spkgGetOpts();

      private:
            spkg_command_t command;
            string spkg_default_root;
            int spkg_check_run_deps;
            int spkg_check_run_conflicts;
            int spkg_check_run_suggests;
            int spkg_run_force_flag;
            int spkg_run_verbose_mode;
            int spkg_run_silent_mode;
};

#endif
