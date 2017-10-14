#include "../libspkg/libspkg.h"
#include "../libspkg/baseConfig.h"
#include "spkgGetOpts.h"

using namespace std;

int main(int argc, char** argv)
{
      char* progname = argv[0];

      setlocale(LC_ALL,"");
      bindtextdomain(progname, "locale");
      textdomain(progname);

      spkgGetOpts Config;

      /* Process arguments */
      Config.spkg_process_arguments(argc, argv);

      /* Stop if no argument was selected */
      /*if (Config.get_spkg_main_command() == SPKG_NONE)
      {
            cout << _("Default command is not defined\n");
            return SPKG_FAILURE;
      }*/

      cout << "CPU Count           : " << Config.get_spkg_cpu_count() << "\n";
      cout << "Memory Count        : " << Config.get_spkg_mem_count(SPKG_GIGABYTES) << "\n";
      cout << "OS Type             : " << Config.get_spkg_os_type() << "\n";
      cout << "Machine             : " << Config.get_spkg_machine() << "\n";
      cout << "Main packages arch  : " << Config.get_spkg_main_pkg_arch() << "\n";
      cout << "Default root        : " << Config.get_spkg_default_root() << "\n";
      cout << "Supported pkg archs : " << "";
      Config.print_spkg_sup_pkg_archs();
      cout << "Default command     : " << Config.get_spkg_main_command() << "\n";
      cout << "Force mode          : " << Config.get_spkg_force_flag() << "\n";
      cout << "Verbose mode        : " << Config.get_spkg_verbose_flag() << "\n";
      cout << "Silent mode         : " << Config.get_spkg_silent_flag() << "\n";
      cout << "Runtime depends     : " << Config.get_spkg_depends_flag() << "\n";
      cout << "Package conflicts   : " << Config.get_spkg_conflicts_flag() << "\n";
      cout << "Package suggestions : " << Config.get_spkg_suggests_flag() << "\n";
      cout << "Package script      : " << Config.get_spkg_script_flag() << "\n";
      
      return EXIT_SUCCESS;
}
