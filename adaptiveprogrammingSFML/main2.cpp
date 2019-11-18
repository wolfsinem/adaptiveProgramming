#include "drawables.hpp"


//cd Desktop/adaptiveprogrammingSFML/
//open main.cpp

//g++ -std=c++17 main2.cpp point.cpp drawables.cpp -o main -DSFML_STATIC -I/Users/wolfsinem/Desktop/SFML/include -L/Users/wolfsinem/Desktop/SFML/lib  -lsfml-graphics -lsfml-window -lsfml-system
//./mainn

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
