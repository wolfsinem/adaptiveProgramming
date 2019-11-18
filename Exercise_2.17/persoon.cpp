# include "persoon.hpp"
// # include ""

ostream& operator<<(ostream& os, const persoon& rhs){
    os << rhs.name<< " heeft een budget van 'EUR' ";
    os << rhs.budget << " en bezit de volgende spellen:"<< std::endl;

    for(game g : rhs.gamelijst){
        os<< g<< " ";
    }
    // Eric heeft een budget van €142.49 en bezit de volgende games:
    // Just Cause 3, uitgegeven in 2015; nieuwprijs: 49.98 nu voor: €34.98
    // Need for Speed: Rivals, uitgegeven in 2014; nieuwprijs: 45.99 nu voor: €22.53
    return os;
};

string persoon::koop(game g){
    bool bezitgame = false;
    for(const game& gamei: gamelijst){
        if(gamei == g){
            bezitgame = true;
        };
    }

    if(!bezitgame && budget > g.huidigewaarde()){
        budget = budget - g.huidigewaarde();
        gamelijst.push_back(g);
        return "Gelukt";
    }
    return "Niet Gelukt" ;
};
void persoon::verkoop(const game& g, persoon p){
    // std::cout<<"gelukt";
    bool bezitgame = false;
    for(const game& gamei: gamelijst){
        if(gamei == g){
            bezitgame = true;
        }
    }
    bool persbezitgame;
    if(bezitgame){
        for(const game& gamei: p.gamelijst){
            if(gamei == g){persbezitgame = true;}
            if(!persbezitgame){   
                if(p.koop(g)== "Gelukt");{        
                    int count= 0;
                    for(game& item : gamelijst){
                        if(item == g){
                            gamelijst.erase(gamelijst.begin()+count);
                            std::cout<<"gelukt";
                        }
                    }
                    count ++;
                }
            }
            else{std::cout<<"niet gelukt";}
        }
    }
    else{
         std::cout<<"niet gelukt";
    }
    // p.gamelijst;
};

