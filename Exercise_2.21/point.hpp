#include <iostream>
using std::cout, std::endl;

class point {
 public:
  int posx;
  int posy;
  point(int posx, int posy) : posx(posx), posy(posy){};
  void operator+=(const point& p);
  point operator+(const point& p);
  void print();
};