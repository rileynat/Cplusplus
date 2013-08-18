#include <istream>
#include <iostream>
#include "color_pixel.h"
using namespace std;

color_pixel::color_pixel() {}

color_pixel::color_pixel(float r, float g, float b) {
  rgb[0] = r;
  rgb[1] = g;
  rgb[2] = b;
}

const float& color_pixel::operator[](size_t index) const {
  return rgb[index];
}

float& color_pixel::operator[](size_t index) {
  return rgb[index];
}

template <typename Ch, typename Tr>
basic_istream<Ch,Tr>& operator>>(basic_istream<Ch,Tr>& istream, color_pixel& p) {
  return istream >> p[0] >> p[1] >> p[2];
}
