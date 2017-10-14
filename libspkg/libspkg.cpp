#include <string>
#include "libspkg.h"

void spkg_render_string_vector(vector<string> list)
{
    vector<string>::iterator it;

    for(it = list.begin(); it != list.end(); it++)
        cout<< *it <<" ";

    cout << "\n";
}
