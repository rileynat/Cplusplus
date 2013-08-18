#include <vector>
#include <cassert>
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <cmath>
//#include <cstdint>
#include "color_pixel.h"
using namespace std;

unsigned int get_sign(float &N) {
  //gets the sign bit from a float
  unsigned char* bytes = reinterpret_cast<unsigned char*>(&N);
  cout << (int)bytes[0] << " " << (int)bytes[1] << " " << (int)bytes[2] << " " << (int)bytes[3] << endl;
  return bytes[3]/128;
}

int get_exponent(float &N) {
  //gets the exponent bits from a float
  unsigned char *bytes = reinterpret_cast<unsigned char*>(&N);
  int temp =  (bytes[2]/128 + 2*(bytes[3]%128));
  if (temp == 0)
    return temp;
  else 
    return temp - 127;
}

unsigned int get_mantissa(float &N) {
  //gets the mantissa from a float
  unsigned char* bytes = reinterpret_cast<unsigned char*>(&N);
  return bytes[0] + 256*bytes[1] + 65536*(bytes[2]%128);
}

void swap_byte_order(float& value) {
  //swaps the bytes of a half float
  unsigned char* bytes = reinterpret_cast<unsigned char*>(&value);
  swap(bytes[0], bytes[3]);
  swap(bytes[1], bytes[2]);
}

void swap_byte_order(short value) {
  //swaps the bytes of a float
  unsigned char* bytes = reinterpret_cast<unsigned char*>(&value);
  swap(bytes[0], bytes[1]);
}

int main (int argc, char *argv[]) {

  //open in file and out file
  string filename = (string)argv[1];
  ifstream in;
  in.open( filename.c_str() );
  if (!in.is_open()) {
    cerr << "in failed" << endl;
    return 1;
  }
  string ofilename = (string)argv[argc - 1];
  ofstream out;
  out.open(ofilename.c_str() );
  if (!out.is_open() ) {
    cerr << "out failed" << endl;
    return 1;
  }
  size_t width = 0, height = 0;
  double byte_order_and_scale = 0.0, scale = 0.0;
  bool greyscale_flag = false, little_edian_flag = false, little_edian_out_flag = false, edian_set = false;
  unsigned int sign, mantissa; 
  int exponent;
  short answer;
  
  //endian flag
  for (int i = 0; i < argc; i++) {
    if (argv[i][0] == '-') {
      edian_set = true;
      if (argv[i+1][0] == 'l') {
	little_edian_out_flag = true;
      }
    }
  }

  //read header
  string line;
  getline(in, line);
  //cout << line;
  if (line[1] == 'F')
    greyscale_flag = false;
  else if (line[1] == 'f') 
    greyscale_flag = true;
  else 
    cerr << "greyscale not set" << endl;
  getline(in, line);
  in >> width;
  in >> height;
  in >> byte_order_and_scale;
  if (!in) {
    cerr << "input failure" << endl;
    return 1;
  }
  if (byte_order_and_scale < 0.0) {
    little_edian_flag = true;
    scale = -byte_order_and_scale;
  }
  else {
    little_edian_flag = false;
    scale = byte_order_and_scale;
  }

  //read pfm file
  vector<vector<color_pixel> > in_image(width, vector<color_pixel>(height));
  
  for (size_t row = 0; row < height; row++) {
    color_pixel* scanline_begin = &in_image[row][0];
    color_pixel* scanline_end = scanline_begin + width;
    for (color_pixel* scanline_iterator = scanline_begin; scanline_iterator != scanline_end; ++scanline_iterator) {
      color_pixel& pixel = *scanline_iterator;
      in.read(reinterpret_cast<char*>(&pixel[0]), 4);
      if (little_edian_flag) {
	swap_byte_order(pixel[0]);
      }
      in.read(reinterpret_cast<char*>(&pixel[1]), 4);
      if (little_edian_flag) {
	swap_byte_order(pixel[1]);
      }
      in.read(reinterpret_cast<char*>(&pixel[2]), 4);
      if (little_edian_flag) {
	swap_byte_order(pixel[2]);
      }
    }
  }

  float N = 0;

  //convert to half float
  if (!greyscale_flag)
    out << "PF" << endl;
  else 
    out << "Pf" << endl;
  out << line << endl;
  out << height << " " << width << endl;
  out << byte_order_and_scale << endl;
  for (size_t i = 0; i < in_image.size(); i++) {
    for (size_t j = 0; j < in_image[i].size(); j++) {
      for (size_t k = 0; k < 3; k++) {
	N = in_image[i][j][k];
	sign = get_sign(N);
	exponent = get_exponent(N);
	mantissa = get_mantissa(N);
	if (exponent > 15) 
	  exponent = 31;
	else if (exponent < -14)
	  exponent = 31;
	else if (exponent != 0)
	  exponent += 15;
	mantissa = mantissa / 8192;
	answer = ((sign << 15) | (exponent << 10) | (mantissa)); 
	if (!little_edian_out_flag)
	  swap_byte_order(answer);
	out << answer;
      }
    }
    out << endl;
  }
}

//credit to Stack Overflow posters for example code
