// BMPSaver.cpp : Defines the exported functions for the DLL.
//

#include "BMPSaver.h"
#include <string>
#include <fstream>

static std::string error;
static std::string returnCache;

/*
	Writes the pixel data to a file, expects {uint8 b, uint8 g, uint8 r}[]
*/
BMPSAVER_API int BMPSave(const uint8_t* pixels, uint32_t w, uint32_t h, const char* filename) try {

	std::ofstream file;
	file.open(filename);

	struct dib_header_t {
		/* Must be 40 */
		uint32_t size;
		int32_t width;
		int32_t height;
		/* Must be 1 */
		uint16_t colorPlaneN;
		/* Bits per pixel, must be 24 */
		uint16_t bpp;
		/* Must be 0, that's no compression */
		uint32_t compression;
		/* Size of pixel data, since we don't use compression leave it at 0 */
		uint32_t imageSize;
		/* Horizontal resolution, pixels per meter */
		int32_t ppmX;
		/* Vertical resolution, pixels per meter */
		int32_t ppmY;
		/* Since we don't use a pallete leave at 0 */
		uint32_t colorPalleteSize;
		/* Unused */
		uint32_t importantColors;

	};

	static_assert(sizeof(dib_header_t) == 40, "DIB header must be 40 bytes long");

	// File identification
	file.write("BM", 2);
	// Size of the file
	uint32_t size = w * h * 3 + 14 + 40;
	file.write((const char *)&size, 4);
	// Custom data
	file.write("BtSK", 4);
	// Offset of pixel data from the start of the file
	uint32_t pixelDataOffset = 14 + 20;
	file.write((const char *)&pixelDataOffset, 4);

	// Dib header
	dib_header_t dibHeader;
	dibHeader.size = sizeof(dib_header_t);
	dibHeader.width = w;
	dibHeader.height = h;
	dibHeader.colorPlaneN = 1;
	dibHeader.bpp = 24;
	dibHeader.compression = 0;
	dibHeader.imageSize = 0;
	dibHeader.ppmX = 100;
	dibHeader.ppmY = 100;
	dibHeader.colorPalleteSize = 0;
	dibHeader.importantColors = 0;

	file.write((const char*)&dibHeader, sizeof(dibHeader));

	// Pixels
	file.write((const char*)pixels, (std::streamsize)w * (std::streamsize)h * 3);

	file.close();

	return 0;
} catch (const std::exception & err) {
	error = err.what();
	return -1;
}

BMPSAVER_API const char* BMPGetError() {
	return error.c_str();
}

