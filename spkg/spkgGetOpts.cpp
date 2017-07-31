//#include <getopt.h>
//#include <unistd.h>
//#include <string>
#include "spkgGetOpts.h"
//#include "../libspkg/libspkg.h"

spkgGetOpts::spkgGetOpts()
{
      /*
      * Initialize default options using macro expansion
      */
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
            { SPKG_HELP_OPTION,    SPKG_NO,  SPKG_NULL,  SPKG_HELP_SHORT_OPTION    },
            { SPKG_INITDB_OPTION,  SPKG_NO,  SPKG_NULL,  SPKG_INITDB_SHORT_OPTION  },
            { SPKG_PACK_OPTION,    SPKG_NO,  SPKG_NULL,  SPKG_PACK_SHORT_OPTION    },
            { SPKG_EXTRACT_OPTION, SPKG_NO,  SPKG_NULL,  SPKG_EXTRACT_SHORT_OPTION },
            { SPKG_INSTALL_OPTION, SPKG_NO,  SPKG_NULL,  SPKG_INSTALL_SHORT_OPTION },
            { SPKG_REMOVE_OPTION,  SPKG_NO,  SPKG_NULL,  SPKG_REMOVE_SHORT_OPTION  },
            { SPKG_UPDATE_OPTION,  SPKG_NO,  SPKG_NULL,  SPKG_UPDATE_SHORT_OPTION  },
            { SPKG_REPLACE_OPTION, SPKG_NO,  SPKG_NULL,  SPKG_REPLACE_SHORT_OPTION },
            { SPKG_QUERY_OPTION,   SPKG_NO,  SPKG_NULL,  SPKG_QUERY_SHORT_OPTION   },
            { SPKG_SHOW_OPTION,    SPKG_NO,  SPKG_NULL,  SPKG_SHOW_SHORT_OPTION    }
      };
}
