#include "point.hpp"
#include <iostream>
using std::cout, std::endl;

void point::operator+=(const point& p) {
posx += p.posx;
posy += p.posy;
}
point point::operator+(const point& p) {
return point(posx + p.posx, posy + p.posy);
}
void point::print() { cout << posx << " " << posy << endl; }
