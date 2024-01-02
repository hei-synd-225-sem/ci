#ifndef __VERSION_H
#define __VERSION_H

/* Getters for version numbers. */

unsigned int get_version_major(void);
unsigned int get_version_minor(void);
unsigned int get_version_patch(void);
const char* get_version_string(void);

#endif //__VERSION_H