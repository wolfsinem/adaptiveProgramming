#ifndef _drawables_hpp
#define _drawables_hpp

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <chrono>
#include <thread>
#include "point.hpp"

class drawable {
 public:
  sf::RenderWindow& w;

  drawable(sf::RenderWindow& w) : w(w){};
  virtual void draw() = 0;
  virtual void update(){};
};

class line : public drawable {
  point b;
  point e;

 public:
  line(sf::RenderWindow& w, point b, point e) : drawable(w), b(b), e(e){};
  void update();
  void draw();
  void move(point x, point y);
};

class square : public drawable {
 public:
  point b;
  point size;
  line top;
  line right;
  line left;
  line bottom;
  bool filled = 1;

  square(sf::RenderWindow& w, point b, point size)
      : drawable(w),
        b(b),
        size(size),
        top(line{w, b, point{b.posx + size.posx, b.posy}}),
        right(line{w, point{b.posx + size.posx, b.posy},
                   point{b.posx + size.posx, b.posy + size.posy}}),
        left(line{w, point{b.posx, b.posy + size.posy}, b}),
        bottom(line{w, point{b.posx, b.posy + size.posy},
                    point{b.posx + size.posx, b.posy + size.posy}}){};
  void update();
  void draw();
};

class victim : public square {
 public:
  victim(sf::RenderWindow& w, point b, point size) : square(w, b, size) {}
  void update();
};

#endif // _drawables_hpp