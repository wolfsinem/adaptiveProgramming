#include "drawables.hpp"

void line::update() {}

void line::draw() {
    sf::VertexArray l(sf::LinesStrip, 2);
    l[0].position = sf::Vector2f(b.posx, b.posy);
    l[1].position = sf::Vector2f(e.posx, e.posy);
    w.draw(l);
}
void line::move(point x, point y) {
    b += x;
    e += y;
}

void square::update() { filled = !filled; }
void square::draw() {
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
void victim::update() {
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

