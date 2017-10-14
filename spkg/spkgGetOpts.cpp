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
      spkg_force_flag = SPKG_FORCE_FLAG;
      spkg_verbose_flag = SPKG_FORCE_FLAG;
      spkg_silent_flag = SPKG_SILENT_FLAG;
      spkg_depends_flag = SPKG_DEPENDS_FLAG;
      spkg_suggests_flag = SPKG_SUGGESTS_FLAG;
      spkg_conflicts_flag = SPKG_CONFLICTS_FLAG;
      spkg_script_flag = SPKG_SCRIPT_FLAG;
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

void spkgGetOpts::set_spkg_main_command(spkg_command_t command)
{
      spkg_main_command = command;
}


spkg_command_t spkgGetOpts::get_spkg_main_command(void)
{
      return spkg_main_command;
}

void spkgGetOpts::set_spkg_default_root(string str)
{
      spkg_default_root = str;
}

string spkgGetOpts::get_spkg_default_root(void)
{
      return spkg_default_root;
}

void spkgGetOpts::set_spkg_force_flag(spkg_flag_t flag)
{
      spkg_force_flag = flag;
}

spkg_flag_t spkgGetOpts::get_spkg_force_flag(void)
{
      return spkg_force_flag;
}

void spkgGetOpts::set_spkg_verbose_flag(spkg_flag_t flag)
{
      spkg_verbose_flag = flag;
}

spkg_flag_t spkgGetOpts::get_spkg_verbose_flag(void)
{
      return spkg_verbose_flag;
}

void spkgGetOpts::set_spkg_silent_flag(spkg_flag_t flag)
{
      spkg_silent_flag = flag;
}

spkg_flag_t spkgGetOpts::get_spkg_silent_flag(void)
{
      return spkg_silent_flag;
}

void spkgGetOpts::set_spkg_depends_flag(spkg_flag_t flag)
{
      spkg_depends_flag = flag;
}

spkg_flag_t spkgGetOpts::get_spkg_depends_flag(void)
{
      return spkg_depends_flag;
}

void spkgGetOpts::set_spkg_conflicts_flag(spkg_flag_t flag)
{
      spkg_conflicts_flag = flag;
}

spkg_flag_t spkgGetOpts::get_spkg_conflicts_flag(void)
{
      return spkg_conflicts_flag;
}

void spkgGetOpts::set_spkg_suggests_flag(spkg_flag_t flag)
{
      spkg_suggests_flag = flag;
}

spkg_flag_t spkgGetOpts::get_spkg_suggests_flag(void)
{
      return spkg_suggests_flag;
}

void spkgGetOpts::set_spkg_script_flag(spkg_flag_t flag)
{
      spkg_script_flag = flag;
}

spkg_flag_t spkgGetOpts::get_spkg_script_flag(void)
{
      return spkg_script_flag;
}

void spkgGetOpts::set_spkg_target_objects(vector<string> targets)
{
      spkg_target_objects = targets;
}

vector<string> spkgGetOpts::get_spkg_taget_objects(void)
{
      return spkg_target_objects;
}

void spkgGetOpts::spkg_process_arguments(int argc, char** argv)
{

      int c;
      int option_index = 0;
      const char* short_options = (char*)SPKG_SHORT_OPTIONS;
      vector<string> targets;
      //opterr = 0;

      while(1)
      {

            //int this_option_optind = optind ? optind : 1;

            const struct option options[] =
            {
                  { SPKG_HELP_OPTION,      no_argument,        SPKG_NULL,  SPKG_HELP_SHORT_OPTION      },
                  { SPKG_INITDB_OPTION,    no_argument,        SPKG_NULL,  SPKG_INITDB_SHORT_OPTION    },
                  { SPKG_PACK_OPTION,      required_argument,  SPKG_NULL,  SPKG_PACK_SHORT_OPTION      },
                  { SPKG_EXTRACT_OPTION,   required_argument,  SPKG_NULL,  SPKG_EXTRACT_SHORT_OPTION   },
                  { SPKG_INSTALL_OPTION,   no_argument,        SPKG_NULL,  SPKG_INSTALL_SHORT_OPTION   },
                  { SPKG_REMOVE_OPTION,    no_argument,        SPKG_NULL,  SPKG_REMOVE_SHORT_OPTION    },
                  { SPKG_UPDATE_OPTION,    required_argument,  SPKG_NULL,  SPKG_UPDATE_SHORT_OPTION    },
                  { SPKG_REPLACE_OPTION,   required_argument,  SPKG_NULL,  SPKG_REPLACE_SHORT_OPTION   },
                  { SPKG_QUERY_OPTION,     required_argument,  SPKG_NULL,  SPKG_QUERY_SHORT_OPTION     },
                  { SPKG_SHOW_OPTION,      required_argument,  SPKG_NULL,  SPKG_SHOW_SHORT_OPTION      },
                  { SPKG_USE_ROOT_OPTION,  required_argument,  SPKG_NULL,  SPKG_USE_ROOT_SHORT_OPTION  },
                  { SPKG_FORCE_OPTION,     no_argument,        SPKG_NULL,  SPKG_FORCE_SHORT_OPTION     },
                  { SPKG_VERBOSE_OPTION,   no_argument,        SPKG_NULL,  SPKG_VERBOSE_SHORT_OPTION   },
                  { SPKG_SILENT_OPTION,    no_argument,        SPKG_NULL,  SPKG_SILENT_SHORT_OPTION    },
                  { SPKG_DEPENDS_OPTION,   no_argument,        SPKG_NULL,  SPKG_DEPENDS_SHORT_OPTION   },
                  { SPKG_CONFLICTS_OPTION, no_argument,        SPKG_NULL,  SPKG_CONFLICTS_SHORT_OPTION },
                  { SPKG_SUGGESTS_OPTION,  no_argument,        SPKG_NULL,  SPKG_SUGGESTS_SHORT_OPTION  },
                  { SPKG_SCRIPT_OPTION,    no_argument,        SPKG_NULL,  SPKG_SCRIPT_SHORT_OPTION    },
                  { 0,                     0,                  0,          0                           },
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
                  case SPKG_USE_ROOT_SHORT_OPTION:
                        set_spkg_default_root(optarg);
                        break;
                  case SPKG_FORCE_SHORT_OPTION:
                        set_spkg_force_flag(SPKG_ON);
                        break;
                  case SPKG_VERBOSE_SHORT_OPTION:
                        set_spkg_verbose_flag(SPKG_ON);
                        set_spkg_silent_flag(SPKG_OFF);
                        break;
                  case SPKG_SILENT_SHORT_OPTION:
                        set_spkg_silent_flag(SPKG_ON);
                        set_spkg_verbose_flag(SPKG_OFF);
                        break;
                  case SPKG_DEPENDS_SHORT_OPTION:
                        set_spkg_depends_flag(SPKG_OFF);
                        break;
                  case SPKG_CONFLICTS_SHORT_OPTION:
                        set_spkg_conflicts_flag(SPKG_OFF);
                        break;
                  case SPKG_SUGGESTS_SHORT_OPTION:
                        set_spkg_suggests_flag(SPKG_OFF);
                        break;
                  case SPKG_SCRIPT_SHORT_OPTION:
                        set_spkg_script_flag(SPKG_OFF);
                        break;
                  case '?':
                        get_spkg_usage();
                        exit(SPKG_FAILURE);
                  default :
                        get_spkg_usage();
            }
      }

      /*
      * Add anything else to targets vector to be Process
      */
      if (optind < argc)
      {
        while (optind < argc)
          targets.push_back(argv[optind++]);
      }

      if (targets.size() > 0)
        set_spkg_target_objects(targets);

      exit(SPKG_SUCCESS);
}
