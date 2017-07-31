#include <iostream>
#include <sys/utsname.h>
#include <sys/sysinfo.h>
#include "libspkg.h"
#include "baseConfig.h"

/*
* Setters definition
*/

using namespace std;

void baseConfig::set_spkg_cpu_count(int count)
{
      spkg_cpu_count = count;
}

int baseConfig::get_spkg_cpu_count(void)
{
      return spkg_cpu_count;
}

void baseConfig::set_spkg_mem_count(unsigned long count)
{
      spkg_mem_count = count;
}

unsigned long baseConfig::get_spkg_mem_count(spkg_unit unit)
{
      switch(unit)
      {
            case SPKG_BYTES     : return spkg_mem_count/1;
            case SPKG_KILOBYTES : return spkg_mem_count/1024;
            case SPKG_MEGABYTES : return spkg_mem_count/1000024;
            case SPKG_GIGABYTES : return spkg_mem_count/1000000024;
            default : return spkg_mem_count/1;
      }
}

void baseConfig::set_spkg_os_type(string str)
{
            spkg_os_type = str;
}

string baseConfig::get_spkg_os_type(void)
{
      return spkg_os_type;
}

void baseConfig::set_spkg_machine(string str)
{
      spkg_machine = str;
}

string baseConfig::get_spkg_machine(void)
{
      return spkg_machine;
}

void baseConfig::set_spkg_main_pkg_arch(string machine)
{
      if(machine == "x86_64")
            spkg_main_pkg_arch = "x64";

      if(machine == "i?86")
            spkg_main_pkg_arch = "x32";
}

string baseConfig::get_spkg_main_pkg_arch(void)
{
      return spkg_main_pkg_arch;
}

void baseConfig::set_spkg_sup_pkg_archs(string main_arch)
{
      spkg_sup_pkg_archs.push_back(main_arch);

      if(main_arch == "x64")
            spkg_sup_pkg_archs.push_back("x32");

      spkg_sup_pkg_archs.push_back("noarch");
}

vector<string> baseConfig::get_spkg_sup_pkg_archs(void)
{
      return spkg_sup_pkg_archs;
}

void baseConfig::print_spkg_sup_pkg_archs(void)
{
      vector<string>::iterator it;

      for(it = spkg_sup_pkg_archs.begin(); it != spkg_sup_pkg_archs.end(); it++)
          cout<< *it <<" ";

      cout << "\n";
}

baseConfig::baseConfig()
{
      spkg_cpu_count = 0;
      spkg_mem_count = -1;
      spkg_os_type = "unknow";
      spkg_machine = "unknow";
      spkg_main_pkg_arch = "unknow";

      struct utsname udata;
      if((uname(&udata)) == 0)
      {
            struct sysinfo sinfo;
            if((sysinfo(&sinfo)) == 0)
            {
                  set_spkg_cpu_count((int)get_nprocs());
                  set_spkg_mem_count(sinfo.totalram);
                  set_spkg_os_type((string)udata.sysname);
                  set_spkg_machine(udata.machine);
                  set_spkg_main_pkg_arch(spkg_machine);
                  set_spkg_sup_pkg_archs(spkg_main_pkg_arch);
            }
      }
}
