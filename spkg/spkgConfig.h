#include "../libspkg/libspkg.h"
#include "../libspkg/baseConfig.h"
#include "spkgGetOpts"

#ifndef SPKGCONFIG_H
#define SPKGCONFIG_H

using namespace std;

class spkgConfig : protected baseConfig
{
public:
      spkgConfig();

private:
      spkg_command_t spkg_main_command;
      string spkg_default_root;
}

#endif
