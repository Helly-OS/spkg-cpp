#include <ctype.h>
#include <getopt.h>
#include <unistd.h>
#include <string>
#include "spkgGetOpts.h"
#include "../libspkg/libspkg.h"

#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

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
      spkg_run_verbose_flag = SPKG_RUN_FORCE_FLAG;
      spkg_run_silent_flag = SPKG_RUN_SILENT_FLAG;

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

void spkgGetOpts::get_spkg_usage(void)
{
      cerr << _("\n"
      "Usage :\n"
      "spkg [main command] [--options] [packages (optional)]\n"
      "\n"
      " -h, --help    Show this help and exit without error\n"
      " -i, --install Install spkg format package\n"
      " -r, --remove  Remove spkg installed package\n"
      ""
      ) << endl;
}

spkg_flag_t spkgGetOpts::get_spkg_force_flag(void)
{
      return spkg_run_force_flag;
}

void spkgGetOpts::set_spkg_force_flag(spkg_flag_t flag)
{
      spkg_run_force_flag = flag;
}

spkg_flag_t spkgGetOpts::get_spkg_verbose_flag(void)
{
      return spkg_run_verbose_flag;
}

void spkgGetOpts::set_spkg_verbose_flag(spkg_flag_t flag)
{
      spkg_run_verbose_flag = flag;
}

spkg_flag_t spkgGetOpts::get_spkg_silent_flag(void)
{
      return spkg_run_silent_flag;
}

void spkgGetOpts::set_spkg_silent_flag(spkg_flag_t flag)
{
      spkg_run_silent_flag = flag;
}


void spkgGetOpts::spkg_process_arguments(int argc, char** argv)
{

      int c;
      int option_index = 0;
      const char* short_options = (char*)SPKG_SHORT_OPTIONS;
      //opterr = 0;

      while(1)
      {

            //int this_option_optind = optind ? optind : 1;

            const struct option options[] =
            {
                  { SPKG_HELP_OPTION,    no_argument,        SPKG_NULL,  SPKG_HELP_SHORT_OPTION    },
                  { SPKG_INITDB_OPTION,  no_argument,        SPKG_NULL,  SPKG_INITDB_SHORT_OPTION  },
                  { SPKG_PACK_OPTION,    required_argument,  SPKG_NULL,  SPKG_PACK_SHORT_OPTION    },
                  { SPKG_EXTRACT_OPTION, required_argument,  SPKG_NULL,  SPKG_EXTRACT_SHORT_OPTION },
                  { SPKG_INSTALL_OPTION, no_argument,        SPKG_NULL,  SPKG_INSTALL_SHORT_OPTION },
                  { SPKG_REMOVE_OPTION,  no_argument,        SPKG_NULL,  SPKG_REMOVE_SHORT_OPTION  },
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
                  { 0,                   0,                  0,          0                         },
            };

            c = getopt_long (argc, argv, short_options, options, &option_index);

            if(c == -1)
                  break;

            switch(c)
            {
                  case SPKG_HELP_SHORT_OPTION:
                        set_spkg_main_command(SPKG_HELP);
                        break;
                  case SPKG_INITDB_SHORT_OPTION:
                        set_spkg_main_command(SPKG_INITDB);
                        break;
                  case SPKG_PACK_SHORT_OPTION:
                        set_spkg_main_command(SPKG_PACK);
                        break;
                  case SPKG_EXTRACT_SHORT_OPTION:
                        set_spkg_main_command(SPKG_EXTRACT);
                        break;
                  case SPKG_INSTALL_SHORT_OPTION:
                        set_spkg_main_command(SPKG_INSTALL);
                        break;
                  case SPKG_REMOVE_SHORT_OPTION:
                        set_spkg_main_command(SPKG_REMOVE);
                        break;
                  case SPKG_UPDATE_SHORT_OPTION:
                        set_spkg_main_command(SPKG_UPDATE);
                        break;
                  case SPKG_REPLACE_SHORT_OPTION:
                        set_spkg_main_command(SPKG_REPLACE);
                        break;
                  case SPKG_QUERY_SHORT_OPTION:
                        set_spkg_main_command(SPKG_QUERY);
                        break;
                  case SPKG_SHOW_SHORT_OPTION:
                        set_spkg_main_command(SPKG_SHOW);
                        break;
                  case SPKG_USE_ROOT_SHORT:
                        set_spkg_default_root(optarg);
                        break;
                  case SPKG_FORCE_FLAG_SHORT:
                        set_spkg_force_flag(SPKG_ON);
                        break;
                  case SPKG_VERBOSE_FLAG_SHORT:
                        set_spkg_verbose_flag(SPKG_ON);
                        set_spkg_silent_flag(SPKG_OFF);
                        break;
                  case SPKG_SILENT_FLAG_SHORT:
                        set_spkg_silent_flag(SPKG_ON);
                        set_spkg_verbose_flag(SPKG_OFF);
                        break;
                  case '?':
                        get_spkg_usage();
                        exit(SPKG_FAILURE);
                  default :
                        get_spkg_usage();
            }
      }
}
