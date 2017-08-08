#include <getopt.h>
#include <unistd.h>
#include <string>
#include "spkgGetOpts.h"
#include "../libspkg/libspkg.h"

spkgGetOpts::spkgGetOpts()
{
      /*
      * Initialize default options using macro expansion
      */
      spkg_main_command = SPKG_NONE;
      spkg_default_root = SPKG_DEFAULT_ROOT;
      spkg_check_run_deps = SPKG_CHECK_RUN_DEPS;
      spkg_check_run_conflicts = SPKG_CHECK_RUN_CONFLICTS;
      spkg_check_run_suggests = SPKG_CHECK_RUN_SUGGESTS;
      spkg_run_force_flag = SPKG_RUN_FORCE_FLAG;
      spkg_run_silent_mode = SPKG_RUN_SILENT_MODE;

      /*
      * Initialize GNU Getopts values
      */
      unsigned short int command = 0;
      short int next_opt;
      const char* short_opts = SPKG_SHORT_OPTIONS;

      const struct option long_opts[] =
      {
            { SPKG_HELP_OPTION,    no_argument,        SPKG_NULL,  SPKG_HELP_SHORT_OPTION    },
            { SPKG_INITDB_OPTION,  no_argument,        SPKG_NULL,  SPKG_INITDB_SHORT_OPTION  },
            { SPKG_PACK_OPTION,    required_argument,  SPKG_NULL,  SPKG_PACK_SHORT_OPTION    },
            { SPKG_EXTRACT_OPTION, required_argument,  SPKG_NULL,  SPKG_EXTRACT_SHORT_OPTION },
            { SPKG_INSTALL_OPTION, required_argument,  SPKG_NULL,  SPKG_INSTALL_SHORT_OPTION },
            { SPKG_REMOVE_OPTION,  required_argument,  SPKG_NULL,  SPKG_REMOVE_SHORT_OPTION  },
            { SPKG_UPDATE_OPTION,  required_argument,  SPKG_NULL,  SPKG_UPDATE_SHORT_OPTION  },
            { SPKG_REPLACE_OPTION, required_argument,  SPKG_NULL,  SPKG_REPLACE_SHORT_OPTION },
            { SPKG_QUERY_OPTION,   required_argument,  SPKG_NULL,  SPKG_QUERY_SHORT_OPTION   },
            { SPKG_SHOW_OPTION,    required_argument,  SPKG_NULL,  SPKG_SHOW_SHORT_OPTION    },
            { SPKG_USE_ROOT,       required_argument,  SPKG_NULL,  SPKG_USE_ROOT_SHORT       },
            { SPKG_FORCE_FLAG,     no_argument,        SPKG_NULL,  SPKG_FORCE_FLAG_SHORT     },
            { SPKG_VERBOSE_FLAG,   no_argument,        SPKG_NULL,  SPKG_VERBOSE_FLAG_SHORT   },
            { SPKG_SILENT_FLAG,    no_argument,        SPKG_NULL,  SPKG_SILENT_FLAG_SHORT    },
            { SPKG_RUNDEPS_FLAG,   no_argument,        SPKG_NULL,  SPKG_RUNDEPS_FLAG_SHORT   },
            { SPKG_CONFLICTS_FLAG, no_argument,        SPKG_NULL,  SPKG_CONFLICTS_FLAG_SHORT },
            { SPKG_SUGGESTS_FLAG,  no_argument,        SPKG_NULL,  SPKG_SUGGESTS_FLAG_SHORT  },
            { SPKG_SCRIPT_FLAG,    no_argument,        SPKG_NULL,  SPKG_SCRIPT_FLAG_SHORT    },
            { 0,                   0,                  0,          0                         }
      };
}

void spkgGetOpts::set_spkg_main_command(spkg_command_t command)
{
      spkg_main_command = command;
}


spkg_command_t spkgGetOpts::get_spkg_main_command(void)
{
      return spkg_main_command;
}

string spkgGetOpts::get_spkg_default_root(void)
{
      return spkg_default_root;
}

void spkgGetOpts::set_spkg_default_root(string str)
{
      spkg_default_root = str;
}

void spkgGetOpts::spkg_process_arguments(int argc, char** argv)
{
      while(1)
      {
            next_opt = getopt_long(argc, argv, short_opts, long_opts, NULL);
            if(next_opt == -1)
                  break;

            switch(next_opt)
            {
                  case SPKG_HELP_SHORT_OPTION:
                        Config.set_spkg_main_command(SPKG_HELP_COMMAND);
                        break;
                  case SPKG_INITDB_SHORT_OPTION:
                        Config.set_spkg_main_command(SPKG_INITDB);
                        break;
                  case '?':
                              exit(SPKG_FAILED);
            }
      }
}
