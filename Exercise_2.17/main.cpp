#include "game.hpp"
#include "persoon.hpp"

#include <iostream>

using std::cout, std::endl;

// g++ -std=c++17 -o main main.cpp game.cpp persoon.cpp; .\main
int main(){
int releaseJaar1 = 2018;
    int releaseJaar2 = 2017;
    game g1("Just Cause 3", releaseJaar1, 4998);
    game g2("Need for Speed: Rivals", releaseJaar2, 4599);
    game g3("Need for Speed: Rivals", releaseJaar2, 4599);
    persoon p1("Eric", 20000);
    persoon p2("Hans", 5500);
    persoon p3("Arno", 18500);
    // Druk de volgende transacties af (pas de code aan)
    
    cout<<"p1 koopt g1: "<<p1.koop(g1)<< endl;
    cout<<"p1 koopt g2: "<<p1.koop(g2)<< endl;
    cout<<"p1 koopt g3: "<<p1.koop(g3)<< endl;
    cout<<"p2 koopt g2: "<<p2.koop(g2)<< endl;
    cout<<"p2 koopt g1: "<<p2.koop(g1)<< endl;
    cout<<"p2 koopt g3: "<<p3.koop(g3)<< endl<<endl;
    // Druk personen p1 p2 p3 nu af naar de console
    cout<<p1<<endl;
    cout<<p2<<endl;
    cout<<p3<<endl;
    // Druk de volgende transacties af (pas de code aan)
    cout<<"p1 verkoopt g1 aan p3: ";
    p1.verkoop(g1, p3);
    cout<<endl;;
    cout<<"p2 verkoopt g2 aan p3: ";
    p2.verkoop(g2, p3);
    cout<<endl;
    cout<<"p2 verkoopt g1 aan p1: ";
    p2.verkoop(g1, p1);
    cout<<endl<<endl;

    cout<<p1<<endl;
    cout<<p2<<endl;
    cout<<p3<<endl;
    return 0;
}
