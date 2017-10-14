#include <string>
#include <vector>

using namespace std;

#ifndef DEFCONFIG_H
#define DEFCONFIG_H

class baseConfig
{
public:
      // Constructor
      baseConfig();

      // Setters
      void set_spkg_cpu_count(int count);
      void set_spkg_mem_count(unsigned long count);
      void set_spkg_os_type(string str);
      void set_spkg_machine(string str);
      void set_spkg_main_pkg_arch(string machine);
      void set_spkg_sup_pkg_archs(string main_arch);

      //Getters
      int get_spkg_cpu_count(void);
      unsigned long get_spkg_mem_count(spkg_unit unit);
      string get_spkg_os_type(void);
      string get_spkg_machine(void);
      string get_spkg_main_pkg_arch(void);
      vector<string> get_spkg_sup_pkg_archs(void);

      // Printers
      void print_spkg_sup_pkg_archs(void);

protected:
      int spkg_cpu_count;
      unsigned long spkg_mem_count;
      string spkg_os_type;
      string spkg_machine;
      string spkg_main_pkg_arch;
      vector<string> spkg_sup_pkg_archs;
};

#endif
