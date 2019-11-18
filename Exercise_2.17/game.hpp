#ifndef _GAME_HPP
#define _GAME_HPP

#include <string>
#include <iostream>

using std::string, std::ostream;

struct game{
    uint32_t waarde;
    string name;
    uint32_t releasejaar;
    uint32_t nieuwprijs;

    game(string name, uint32_t release, uint32_t nieuwprijs)
        :name(name), releasejaar(release), nieuwprijs(nieuwprijs){};
    
    uint32_t huidigewaarde();
    
    friend ostream& operator<<(ostream& os,const game rhs);
    friend bool operator==(const game& lhs, const game& rhs);
};


#endif // _GAME_HPP