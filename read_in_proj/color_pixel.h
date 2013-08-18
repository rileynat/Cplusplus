#include <istream>
#include <iostream>

class color_pixel {
public:
  color_pixel();
  color_pixel(float, float, float);
  const float& operator[](size_t) const;
  float& operator[](size_t);
private:
  float rgb[3];
};

template <typename Ch, typename Tr> std::basic_istream<Ch,Tr>& operator>>(std::basic_istream<Ch,Tr>&, color_pixel&);
//credit for operator overload function format to Prof. Igor Markov
