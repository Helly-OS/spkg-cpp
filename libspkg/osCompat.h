#include <cstring>
#include <iostream>
#include "libspkg.h"

#ifndef OSCOMPAT_H
#define OSCOMPAT_H

using namespace std;

/*
* Implement interface to unix commnds
* - mkdir
* - rmdir
* - cp
* - mv
* - rm
* - stat
*/

typedef enum
{
      SUCCESS,
      FAILURE,
      DIR_NOT_FOUND,
      FILE_NOT_FOUN,
      NOT_ALLOWED,
      FAIL_TO_CREATE_DIR,
      FAIL_TO_CREATE_FILE,
} spkg_os_compat_return_code_t;

class osCompat
{
public:
      spkg_os_compat_return_code_t mkpath(string path, int perms);
};

#endif
