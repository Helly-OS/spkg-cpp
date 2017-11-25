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
      SPKG_FILESYSTEM,
      SPKG_CREATE,
      SPKG_EXPLODE,
      SPKG_INSTALL,
      SPKG_REMOVE,
      SPKG_UPDATE,
      SPKG_QUERY,
} spkg_command_t;

typedef enum
{
      SPKG_EVERYTHING_OK,
      SPKG_NO_GIVEN_OPTION,
      SPKG_UNKNOW_OPTION,
      SPKG_REQUIRE_ARGUMENT,
} spkg_getopt_staus_t;

// Define main options
#define SPKG_HELP_OPTION             "help"
#define SPKG_HELP_SHORT_OPTION       'h'
#define SPKG_INSTALL_OPTION          "install"
#define SPKG_INSTALL_SHORT_OPTION    'i'
#define SPKG_REMOVE_OPTION           "remove"
#define SPKG_REMOVE_SHORT_OPTION     'r'
#define SPKG_UPDATE_OPTION           "update"
#define SPKG_UPDATE_SHORT_OPTION     'u'
#define SPKG_QUERY_OPTION            "query"
#define SPKG_QUERY_SHORT_OPTION      'q'


#define SPKG_CREATE_OPTION           "create"
#define SPKG_CREATE_SHORT_OPTION     10000
#define SPKG_EXPLODE_OPTION          "explode"
#define SPKG_EXPLODE_SHORT_OPTION    10001
#define SPKG_FILESYSTEM_OPTION       "filesystem"
#define SPKG_FILESYSTEM_SHORT_OPTION 10002



// Define options
#define SPKG_USE_ROOT_OPTION        "root"
#define SPKG_USE_ROOT_SHORT_OPTION  'R'
#define SPKG_VERBOSE_OPTION         "verbose"
#define SPKG_VERBOSE_SHORT_OPTION   'v'
#define SPKG_FORCE_OPTION           "force"
#define SPKG_FORCE_SHORT_OPTION     'f'
#define SPKG_SILENT_OPTION          "silent"
#define SPKG_SILENT_SHORT_OPTION    's'

// Define spkg reverse options
#define SPKG_DEPENDS_OPTION         "nodepends"
#define SPKG_DEPENDS_SHORT_OPTION   1000
#define SPKG_CONFLICTS_OPTION       "noconflicts"
#define SPKG_CONFLICTS_SHORT_OPTION 1001
#define SPKG_SUGGESTS_OPTION        "nosuggests"
#define SPKG_SUGGESTS_SHORT_OPTION  1002
#define SPKG_SCRIPT_OPTION          "noscript"
#define SPKG_SCRIPT_SHORT_OPTION    1003

// And define short options
#define SPKG_SHORT_OPTIONS          "hiruq:R:vfs"

// Define default runtime flags
#define SPKG_DEFAULT_ROOT         "/"
#define SPKG_FORCE_FLAG          SPKG_OFF
#define SPKG_VERBOSE_FLAG        SPKG_OFF
#define SPKG_SILENT_FLAG         SPKG_OFF
#define SPKG_DEPENDS_FLAG        SPKG_ON
#define SPKG_CONFLICTS_FLAG      SPKG_ON
#define SPKG_SUGGESTS_FLAG       SPKG_ON
#define SPKG_SCRIPT_FLAG         SPKG_ON

class spkgGetOpts : public baseConfig
{
      public:
            /*
            * Getters and constructor always will be public
            */
            spkgGetOpts();
            spkg_command_t get_spkg_main_command(void);
            string get_spkg_default_root(void);
            spkg_flag_t get_spkg_check_run_deps(void);
            spkg_flag_t get_spkg_force_flag(void);
            spkg_flag_t get_spkg_verbose_flag(void);
            spkg_flag_t get_spkg_silent_flag(void);
            spkg_flag_t get_spkg_depends_flag(void);
            spkg_flag_t get_spkg_conflicts_flag(void);
            spkg_flag_t get_spkg_suggests_flag(void);
            spkg_flag_t get_spkg_script_flag(void);
            vector<string> get_spkg_taget_objects(void);
            spkg_getopt_staus_t spkg_process_arguments(int argc, char** argv);

      private:
            /*
            * Attributes, setters and usage method allways will be private
            */
            spkg_command_t spkg_main_command;
            string spkg_default_root;
            spkg_flag_t spkg_force_flag;
            spkg_flag_t spkg_verbose_flag;
            spkg_flag_t spkg_silent_flag;
            spkg_flag_t spkg_depends_flag;
            spkg_flag_t spkg_suggests_flag;
            spkg_flag_t spkg_conflicts_flag;
            spkg_flag_t spkg_script_flag;
            vector<string> spkg_target_objects;

            void set_spkg_main_command(spkg_command_t command);
            void set_spkg_default_root(string str);
            void set_spkg_force_flag(spkg_flag_t);
            void set_spkg_verbose_flag(spkg_flag_t);
            void set_spkg_silent_flag(spkg_flag_t);
            void set_spkg_depends_flag(spkg_flag_t);
            void set_spkg_conflicts_flag(spkg_flag_t);
            void set_spkg_suggests_flag(spkg_flag_t);
            void set_spkg_script_flag(spkg_flag_t);
            void set_spkg_target_objects(vector<string>);
            void get_spkg_usage(void);
};

#endif
