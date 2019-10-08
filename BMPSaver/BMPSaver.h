// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the BMPSAVER_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// BMPSAVER_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef BMPSAVER_EXPORTS
#define BMPSAVER_API __declspec(dllexport)
#else
#define BMPSAVER_API __declspec(dllimport)
#endif
#include <cstdint>

extern "C" {
	BMPSAVER_API int BMPSave(const uint8_t* pixels, uint32_t w, uint32_t h, const char* filename);
	BMPSAVER_API const char* BMPGetError();
}
