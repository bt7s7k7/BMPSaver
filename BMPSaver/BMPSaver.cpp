// BMPSaver.cpp : Defines the exported functions for the DLL.
//

#include "BMPSaver.h"
#include <string>

static std::string error;
static std::string returnCache;


int BMPSave(uint8_t* pixels, std::size_t w, std::size_t h, const char* filename) try {
	return 0;
} catch (const std::exception & err) {
	error = err.what();
	return -1;
}

const char* BMPGetError() {
	return error.c_str();
} 

