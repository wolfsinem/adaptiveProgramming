#include "game.hpp"

uint32_t game::huidigewaarde(){
    uint32_t release = releasejaar;
    uint32_t output = nieuwprijs;

    while (release < 2019){
        output = output * 0.7;
        release++;    
    }
    waarde = output;
    return output;
};

bool operator==(const game& lhs, const game& rhs){
    if(lhs.name != rhs.name){
        return false;
    }
    if(lhs.releasejaar != rhs.releasejaar){
        return false;
    }
    return true; 
}

ostream& operator<<(ostream& os, game rhs){
        os << rhs.name << ", uitgegeven in " << rhs.releasejaar << "; nieuwprijs: " << rhs.nieuwprijs << " nu voor :"<<rhs.huidigewaarde()<< std::endl;
        return os;
}
    // Eric heeft een budget van €142.49 en bezit de volgende games:
    // Just Cause 3, uitgegeven in 2015; nieuwprijs: 49.98 nu voor: €34.98
    // Need for Speed: Rivals, uitgegeven in 2014; nieuwprijs: 45.99 nu voor: €22.53