#include <cstdlib>
#include <string>
#include <iostream>

#include "../libspkg/libspkg.h"
#include "../libspkg/baseConfig.h"
#include "spkgGetOpts.h"

using namespace std;

int main(int argc, char* argv[])
{
      baseConfig Config;

      cout << "CPU Count           : " << Config.get_spkg_cpu_count() << "\n";
      cout << "Memory Count        : " << Config.get_spkg_mem_count(SPKG_GIGABYTES) << "\n";
      cout << "OS Type             : " << Config.get_spkg_os_type() << "\n";
      cout << "Machine             : " << Config.get_spkg_machine() << "\n";
      cout << "Main packages arch  : " << Config.get_spkg_main_pkg_arch() << "\n";
      cout << "Supported pkg archs : " << "";
      Config.print_spkg_sup_pkg_archs();

      return SPKG_SUCCESS;
}
