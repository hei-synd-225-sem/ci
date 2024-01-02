#include "version.h"

/* Version numbers. */

#define API_MAJOR   1
#define API_MINOR   0
#define API_PATCH   0
#define VERSION     "1.0.0"

unsigned int get_version_major(void)
{
    return API_MAJOR;
}
unsigned int get_version_minor(void)
{
    return API_MINOR;
}
unsigned int get_version_patch(void)
{
    return API_PATCH;
}
const char* get_version_string(void)
{
    return VERSION;
}
