#include <cstdlib>

#ifndef LIBSPKG_H

#define SPKG_YES                    1
#define SPKG_NO                     0
#define SPKG_NULL                   NULL
#define SPKG_EMPTY                  "Empty"
#define SPKG_SUCCESS                EXIT_SUCCESS
#define SPKG_FAILURE                EXIT_FAILURE

typedef enum
{
    SPKG_BYTES,
    SPKG_KILOBYTES,
    SPKG_MEGABYTES,
    SPKG_GIGABYTES
} spkg_unit;

typedef enum
{
      x86_64,
      i686,
      ARM,
      ALPHA,
      POWER8,
      AMIGA
} spkg_arch;

#endif
