#include <iostream> 
#include <sstream>
#include <iomanip>
using namespace std; 

//g++ -std=c++17 Autohuur.cpp -o main
//./main

const string undefined{"undefined"};

class Klant{

    private:
    
    double kortingsPercentage=0.0;
    public:
    string naam;
    Klant(const string& nm = "undefined"){
        naam = nm;
    }
    void setKorting(double kP){
        kortingsPercentage = kP;
    }
    double getKorting(){
        return kortingsPercentage;
    }
    string toString(){
        if(naam == undefined){
            return "er is geen huurder bekent";
        }
        else{
            ostringstream oss;
            oss<<"op naam van: "<<naam<<" (korting: "<<kortingsPercentage<<"%)"<<fixed << setprecision(2);
            return oss.str();
        }
    }
};
class Auto{

    private:
    string type;
    double prijsPerDag;
    public:
    Auto(string tp = "undefined", double prPd = 0.0){
        type = tp;
        prijsPerDag = prPd;
    }
    void setPrijsPerDag(double prPd){
        prijsPerDag = prPd;
    }
    double getPrijsPerDag(){
        return prijsPerDag;
    }
    string getType(){
        return type;
    }
    string toString(){
        if(type == undefined){
            return "er is geen auto bekent";
        }
        else{
            ostringstream oss;
            oss<<type<<" met de prijs per dag: "<<prijsPerDag;
            return oss.str();
        }
    }
};

class AutoHuur{
        public:
    int aantalDagen;
    Klant klant;
    Auto car;
    AutoHuur(){
        aantalDagen = 0;
    }
    void setAantalDagen(int aD){
        aantalDagen = aD;
    }
    void setGehuurdeAuto(Auto gA){
        car = gA;
    }
    Auto getGehuurdeAuto(){
        return car;
    }
    void setHuurder(const Klant& k){
        klant = k;
    }
    Klant getHuurder(){
        return klant;
    }
    double totaalPrijs(){
        return car.getPrijsPerDag()*((100-klant.getKorting())/100)*aantalDagen;
    }
    string toString(){
        ostringstream oss;
        oss << endl << car.toString() << endl << klant.toString()<<endl<< "aantal dagen: " << aantalDagen << fixed << setprecision(1)<<" en dat kost "<< totaalPrijs();
        return oss.str();
    }
};

int main(){
    AutoHuur ah1{};
    cout<<"Eerste autohuur: " + ah1.toString()<<endl<<endl;   // Print "Eerste autohuur: " + ah1.toString()
    Klant k("Mijnheer de Vries");
    k.setKorting(10.0);
    ah1.setHuurder(k);
    cout<<"Eerste autohuur: " + ah1.toString()<<endl<<endl;   // Print: "Eerste autohuur: " + ah1.toString()
    Auto a1("Peugeot 207", 50.0);
    ah1.setGehuurdeAuto(a1);
    ah1.setAantalDagen(4);
    cout<<"Eerste autohuur: " + ah1.toString()<<endl<<endl;   // Print "Eerste autohuur:" + ah1.toString()
    AutoHuur ah2{};
    Auto a2("Ferrari", 3500);
    ah2.setGehuurdeAuto(a2);
    ah2.setHuurder(k);
    ah2.setAantalDagen(1);
    cout<<"Tweede autohuur: " + ah2.toString()<<endl<<endl;   // Print "Tweede autohuur: " + ah2.toString()
    cout<<"Gehuurd: " + ah1.getGehuurdeAuto().toString()<<endl;       // Print "Gehuurd: " + ah1.getGehuurdeAuto()
    cout<<"Gehuurd: " + ah2.getGehuurdeAuto().toString();       // Print "Gehuurd: " + ah2.getGehuurdeAuto()
}
