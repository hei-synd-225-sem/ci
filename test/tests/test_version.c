#include "version.h"
#include "unity.h"

#include <stdlib.h>
#include <string.h>

void setUp(void)
{
    /* Set stuff up here */
}

void tearDown(void)
{
    /* Clean stuff up here */
}

void test_version_number(void)
{
    /* Local variables */
    char errorMessage[512];
    char majorMinorPatch[64];
    char versionString[64];
    const char * versionStringPtr;
    unsigned int major_AsAUInt;
    unsigned int minor_AsAUInt;
    unsigned int patch_AsAUInt;

    /* Ensure MAJOR MINOR and PATCH are positive */
    TEST_ASSERT_TRUE_MESSAGE( get_version_major() >= 0," MAJOR version number should be positive");
    TEST_ASSERT_TRUE_MESSAGE( get_version_minor() >= 0," MINOR version number should be positive");
    TEST_ASSERT_TRUE_MESSAGE( get_version_patch() >= 0," PATCH version number should be positive");

    /* Ensure MAJOR MINOR and PATCH are unsigned integer */
    major_AsAUInt = (unsigned int)abs((int)floor(get_version_major()));
    minor_AsAUInt = (unsigned int)abs((int)floor(get_version_minor()));
    patch_AsAUInt = (unsigned int)abs((int)floor(get_version_patch()));
    sprintf(errorMessage, " MAJOR should be an unsigned int : expected %d got %ud", major_AsAUInt, get_version_major());
    TEST_ASSERT_EQUAL_UINT_MESSAGE(major_AsAUInt, get_version_major(), errorMessage);
    sprintf(errorMessage, " MINOR should be an unsigned int : expected %d got %ud", minor_AsAUInt, get_version_minor());
    TEST_ASSERT_EQUAL_UINT_MESSAGE(minor_AsAUInt, get_version_minor(), errorMessage);
    sprintf(errorMessage, " PATCH should be an unsigned int : expected %d got %ud", patch_AsAUInt, get_version_patch());
    TEST_ASSERT_EQUAL_UINT_MESSAGE(patch_AsAUInt, get_version_patch(), errorMessage);

    /* Ensure MAJOR MINOR PATCH combo matches VERSION string */
    versionStringPtr = get_version_string();
    sprintf(majorMinorPatch, "%d.%d.%d", get_version_major(), get_version_minor(), get_version_patch());
    strcpy(versionString, versionStringPtr);
    sprintf(errorMessage, " VERSION String does not match MAJOR MINOR PATCH : expected %s got %s", majorMinorPatch, versionString);
    TEST_ASSERT_EQUAL_STRING_MESSAGE(majorMinorPatch, versionString, errorMessage);
}
