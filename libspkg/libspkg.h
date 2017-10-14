#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>
#include <libintl.h>
#include <locale.h>

using namespace std;

#ifndef LIBSPKG_H
#define LIBSPKG_H

#ifndef _
#define _(STRING) gettext(STRING)
#endif


typedef enum
{
      SPKG_OFF = 0,
      SPKG_ON
} spkg_flag_t;

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
      ARM
} spkg_arch;

void spkg_render_string_vector(vector<string>);

#endif
