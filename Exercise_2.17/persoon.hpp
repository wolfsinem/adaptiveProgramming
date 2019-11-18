#ifndef _PERSOON_HPP
#define _PERSOON_HPP

#include "game.hpp"

#include <string>
#include <iostream>
#include <vector>

using std::string, std::ostream, std::vector;



class persoon{
    string name;
    uint32_t budget;
    vector<game> gamelijst;

    public:
    persoon(string name, uint32_t budget, vector<game> games = {})
        : name(name), budget(budget), gamelijst(games){}
    
    string koop(game g);
    void verkoop(const game&, persoon p);
    

    friend ostream& operator<<(ostream& os, const persoon& rhs);
};

#endif // _PERSOON_HPP