#include "../BMPSaver/BMPSaver.h"
#include <stdexcept>
#include <iostream>
#include <vector>

constexpr std::size_t w = 20;
constexpr std::size_t h = 20;


int main() try {
	std::vector<uint8_t> image;
	image.resize(w * h * 3);

	for (std::size_t x = 0; x < w; x++) 
		for (std::size_t y = 0; y < h; y++) {
			image[(x + y * w) * 3 + 2] = static_cast<uint8_t>(x * 255 / w);
			image[(x + y * w) * 3 + 1] = static_cast<uint8_t>((w - x) * 255 / w);
			image[(x + y * w) * 3 + 0] = static_cast<uint8_t>(255);
	}

	if (BMPSave(image.data(), w, h, "./test.bmp") == -1) throw std::runtime_error(BMPGetError());


} catch (const std::exception & err) {
	std::cerr << err.what();
}