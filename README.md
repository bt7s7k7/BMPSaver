# BMPSaver
Simple dll to save images as bmp files.
## Example 
````c++
constexpr std::size_t w = 20;
constexpr std::size_t h = 20;

int main() try {
  std::vector<uint8_t> image;
  // Allocate space for image
  image.resize(w * h * 3);

  for (std::size_t x = 0; x < w; x++)
    for (std::size_t y = 0; y < h; y++) {
      // Create a simple gradient, the pixel data should be {uint8 b, uint8 g, uint8 r}[]
      image[(x + y * w) * 3 + 2] = static_cast<uint8_t>(x * 255 / w);
      image[(x + y * w) * 3 + 1] = static_cast<uint8_t>((w - x) * 255 / w);
      image[(x + y * w) * 3 + 0] = static_cast<uint8_t>(255);
  }

  // BMPSave function saves the image, if there was an error, returns -1
  int errorCode = BMPSave(image.data(), w, h, "./test.bmp");
  // Use BMPGetError to get the error message
  if (errorCode == -1) throw std::runtime_error(BMPGetError());

} catch (const std::exception & err) {
  std::cerr << err.what();
}
````
