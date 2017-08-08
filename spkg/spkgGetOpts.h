#include <getopt.h>
#include <unistd.h>
#include <string>
#include "../libspkg/libspkg.h"
#include "../libspkg/baseConfig.h"

using namespace std;

#ifndef SPKGGETOPTS_H
#define SPKGGETOPTS_H

typedef enum
{
      SPKG_NONE,
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

// Define main options
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

// Define flags
#define SPKG_USE_ROOT               "root"
#define SPKG_USE_ROOT_SHORT         'R'
#define SPKG_VERBOSE_FLAG           "verbose"
#define SPKG_VERBOSE_FLAG_SHORT     'v'
#define SPKG_FORCE_FLAG             "force"
#define SPKG_FORCE_FLAG_SHORT       'f'
#define SPKG_SILENT_FLAG            "silent"
#define SPKG_SILENT_FLAG_SHORT      'S'

// Define spkg reverse flags
#define SPKG_RUNDEPS_FLAG           "norundeps"
#define SPKG_RUNDEPS_FLAG_SHORT     1000
#define SPKG_CONFLICTS_FLAG         "noclonflicts"
#define SPKG_CONFLICTS_FLAG_SHORT   1001
#define SPKG_SUGGESTS_FLAG          "nosuggests"
#define SPKG_SUGGESTS_FLAG_SHORT    1002
#define SPKG_SCRIPT_FLAG            "noscript"
#define SPKG_SCRIPT_FLAG_SHORT      1003

// And define short flags
#define SPKG_SHORT_OPTIONS          "hIp:e:i:r:u:R:q:s:"

#define SPKG_DEFAULT_ROOT       "/"
#define SPKG_CHECK_RUN_DEPS       SPKG_ON
#define SPKG_CHECK_RUN_CONFLICTS  SPKG_ON
#define SPKG_CHECK_RUN_SUGGESTS   SPKG_ON
#define SPKG_RUN_PKG_SCRIPT       SPKG_ON
#define SPKG_RUN_FORCE_FLAG       SPKG_OFF
#define SPKG_RUN_VERBOSE_MODE     SPKG_OFF
#define SPKG_RUN_SILENT_MODE      SPKG_OFF

class spkgGetOpts : public baseConfig {
      public:
            spkgGetOpts();
            spkg_command_t get_spkg_main_command(void);
            void set_spkg_main_command(spkg_command_t command);
            string get_spkg_default_root(void);
            void set_spkg_default_root(string str);
            spkg_flag_t get_spkg_check_run_deps(void);
            void set_spkg_check_run_deps(spkg_flag_t);


      private:
            spkg_command_t spkg_main_command;
            string spkg_default_root;
            int spkg_check_run_deps;
            int spkg_check_run_conflicts;
            int spkg_check_run_suggests;
            int spkg_run_force_flag;
            int spkg_run_verbose_mode;
            int spkg_run_silent_mode;

      protected:
            void spkg_process_arguments(int argc, char** argv);


};

#endif
