#include <emscripten.h>
#include <cmath>

extern "C" void EMSCRIPTEN_KEEPALIVE convFilter (unsigned char* data, int width, int height, char* kern, int kWidth, int kHeight, int divisor) {
  int r, g, b;
  int yy, xx, imageOffset, kernelOffset, pix;
  int kCenterY = floor(kHeight / 2);
  int kCenterX = floor(kWidth / 2);
  for (int y = kCenterY; y < height - kCenterY; ++y) {
    for (int x = kCenterX; x < width - kCenterX; ++x) {
      r = 0;
      g = 0;
      b = 0;
      for (int ky = 0; ky < kHeight; ++ky) {
        for (int kx = 0; kx < kWidth; ++kx) {
          imageOffset = (width * (y - kCenterY + ky) + (x - kCenterX + kx)) * 4;
          kernelOffset = kWidth * ky + kx;
          // doing convolution;
          r += data[imageOffset + 0] * kern[kernelOffset];
          g += data[imageOffset + 1] * kern[kernelOffset];
          b += data[imageOffset + 2] * kern[kernelOffset];
        }
      }                 
      pix = (width * y + x) * 4;
      data[pix + 0] =  ((r / divisor) > 255) ? 255 : ((r / divisor) < 0) ? 0 : r / divisor;
      data[pix + 1] =  ((g / divisor) > 255) ? 255 : ((g / divisor) < 0) ? 0 : g / divisor;
      data[pix + 2] =  ((b / divisor) > 255) ? 255 : ((b / divisor) < 0) ? 0 : b / divisor;
    }
  }
}
