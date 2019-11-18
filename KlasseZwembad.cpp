#include <iostream> 
#include <vector>
using namespace std; 

class Zwembad{
public:
    Zwembad(){

    }
    Zwembad(double newBreedte, double newLengte, double newDiepte){
        Breedte = newBreedte;
        Lengte = newLengte;
        Diepte = newDiepte;
    }
    void setBreedte(double newBreedte){
        Breedte = newBreedte;
    }
    void setLengte(double newLengte){
        Lengte = newLengte;
    }
    void setDiepte(double newDiepte){
        Diepte = newDiepte;
    }
    void getBreedte(){
        cout<< "BREEDTE: "<< Breedte << endl;
    }
    void getLengte(){
        cout<< "LENGTE: "<< Lengte << endl;
    }
    void getDiepte(){
        cout<< "DIEPTE: "<< Diepte << endl;
    }
    void inhoud(){
        double inhoud = Breedte*Lengte*Diepte;
        cout<< "BEREKENDE INHOUD: "<< inhoud << endl;
    }
    void toString(){
        cout<< "GEGEVENS ZWEMBAD: Dit zwembad is "<<Breedte<<" meter breed, "<<Lengte<<" meter lang, en "<<Diepte<<" meter diep"<<endl;
    }

private:
double Breedte;
double Lengte;
double Diepte;
};

int main(){
    Zwembad z1(2.0, 5.5, 1.5);

    z1.getBreedte();
    z1.getLengte();
    z1.getDiepte();
    z1.inhoud();
    cout<<endl;

    Zwembad z2;
    z2.setBreedte(2.5);
    z2.setLengte(100.0);
    z2.setDiepte(2.0);

    z2.toString();
    z2.inhoud();

}