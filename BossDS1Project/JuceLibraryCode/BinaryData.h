/* =========================================================================================

   This is an auto-generated file: Any edits you make may be overwritten!

*/

#pragma once

namespace BinaryData
{
    extern const char*   background_png;
    const int            background_pngSize = 122042;

    extern const char*   knob_large_png;
    const int            knob_large_pngSize = 18715;

    extern const char*   knob_small_png;
    const int            knob_small_pngSize = 5457;

    extern const char*   libCircuitModel_a;
    const int            libCircuitModel_aSize = 379816;

    extern const char*   libCircuitModel_a2;
    const int            libCircuitModel_a2Size = 612264;

    extern const char*   CircuitModel_lib;
    const int            CircuitModel_libSize = 1356892;

    extern const char*   CircuitModel_lib2;
    const int            CircuitModel_lib2Size = 703994;

    extern const char*   CircuitModel_lib3;
    const int            CircuitModel_lib3Size = 1002040;

    extern const char*   CircuitModel_lib4;
    const int            CircuitModel_lib4Size = 702212;

    // Number of elements in the namedResourceList and originalFileNames arrays.
    const int namedResourceListSize = 9;

    // Points to the start of a list of resource names.
    extern const char* namedResourceList[];

    // Points to the start of a list of resource filenames.
    extern const char* originalFilenames[];

    // If you provide the name of one of the binary resource variables above, this function will
    // return the corresponding data and its size (or a null pointer if the name isn't found).
    const char* getNamedResource (const char* resourceNameUTF8, int& dataSizeInBytes);

    // If you provide the name of one of the binary resource variables above, this function will
    // return the corresponding original, non-mangled filename (or a null pointer if the name isn't found).
    const char* getNamedResourceOriginalFilename (const char* resourceNameUTF8);
}
