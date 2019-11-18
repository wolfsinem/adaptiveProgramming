//g++ -std=c++17 main.cpp -o main -DSFML_STATIC -I/Users/wolfsinem/Desktop/SFML/include -L/Users/wolfsinem/Desktop/SFML/lib  -lsfml-graphics -lsfml-window -lsfml-system

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <chrono>
#include <iostream>
#include <thread>
using std::cout, std::endl;

class point {
 public:
  int posx;
  int posy;
  point(int posx, int posy) : posx(posx), posy(posy){};
  void operator+=(const point& p) {
    posx += p.posx;
    posy += p.posy;
  }
  point operator+(const point& p) {
    return point(posx + p.posx, posy + p.posy);
  }
  void print() { cout << posx << " " << posy << endl; }
};

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

  void update() {  }

  void draw() override {
    sf::VertexArray l(sf::LinesStrip, 2);
    l[0].position = sf::Vector2f(b.posx, b.posy);
    l[1].position = sf::Vector2f(e.posx, e.posy);
    w.draw(l);
  }
  void move(point x, point y) {
    b += x;
    e += y;

  }
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
  void update() { filled = !filled; }
  void draw() override {
    if (filled) {
      top.draw();
      right.draw();
      bottom.draw();
      left.draw();
    } else {
      sf::RectangleShape vierkant(sf::Vector2f(size.posx, size.posy));
      vierkant.setOrigin(-(b.posx), -(b.posy));
      w.draw(vierkant);
    }
  }
};
class victim : public square {
 public:
  victim(sf::RenderWindow& w, point b, point size) : square(w, b, size) {}
  
  void update() override {
    top.move(point{1, 1}, point{-1, 1});
    right.move(point{-1, 1}, point{-1, -1});
    left.move(point{1, -1}, point{1, 1});
    bottom.move(point{1, -1}, point{-1, -1});
    size.posx -= 2;

    if (size.posx >= 0) {
      top.draw();
      right.draw();
      bottom.draw();
      left.draw();
    } else {
      w.close();
    }
  }
};

int main() {
  sf::RenderWindow window(sf::VideoMode(700, 700), "SFML window");

  point beginpunt{100, 100};
  point eindpunt{300, 400};
  line l1{window, beginpunt, eindpunt};

  point b{200, 200};
  point e{500, 500};
  line l2{window, b, e};


  point bpunt{100, 200};
  point size{300, 300};
  square vierkant{window, bpunt, size};
  
  point s{500, 500};
  victim v{window, b, s};

  std::vector<drawable*> drawables{&l1, &l2, &vierkant, &v};

  while (window.isOpen()) {

    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) window.close();
    }
    window.clear();

    for(drawable* d: drawables){
      d->update();
      d->draw();
    }

    window.display();
    std::this_thread::sleep_for(std::chrono::milliseconds(30));

  }
  return 0;
}
