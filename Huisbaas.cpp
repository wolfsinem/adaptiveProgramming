#include <iostream> 
using namespace std; 

class Persoon{
    private:
    string naam;
    int leeftijd;
    public:
    Persoon(){
        naam = "*Empty";
        leeftijd = 0;
    }
    Persoon(string newNaam, int newLeeftijd){
        naam = newNaam;
        leeftijd = newLeeftijd;
    }
    string toString(){
        auto l = std::to_string(leeftijd);
        return naam + "; leeftijd " + l + " jaar\n";
    }
};

class Huis{
    private:
    Persoon huisbaas;
    string adres;
    int bouwjaar;
    public:
    Huis(string newAdres, int newbouwjaar){
        adres = newAdres;
        bouwjaar = newbouwjaar;
    }
    void setHuisbaas(Persoon p){
        huisbaas = p;
    }
    string getHuisbaas(){
        return huisbaas.toString();
    }
    string toString(){
        auto b = std::to_string(bouwjaar);
        return "Huis " + adres + " is gebouwd in " + b + "\nen heeft huisbaas "+ huisbaas.toString();
    }
    
};

int main(){
    Huis h1("Nijenoord 1", 1970);
    Persoon p1("Ronald Plasterk", 52); 
    h1.setHuisbaas(p1);
    cout<<h1.toString();
    cout<<endl;
    Huis h2("Vredenburg", 1991);
    Persoon p2("Annie Brouwers", 59);
    h2.setHuisbaas(p2);
    cout<<h2.toString();
    cout<<endl;
    cout<< "Huisbaas 1: "+ h1.getHuisbaas();
    cout<< "Huisbaas 2: "+ h2.getHuisbaas();
}