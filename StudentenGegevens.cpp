#include <iostream> 
#include <vector>
#include <iomanip>
using namespace std; 

struct StudentGegevens {
    string VolledigeNaam;
    int leeftijd;
    vector<double> cijferlijst;
    string huisdier;
};

struct KlasGegevens {
    string klasnaam;
    vector<StudentGegevens> studentenlijst;
    string docent;
};

int main(){
    StudentGegevens Gijsbert {"Gijsbertus Antonius Nutma",   18, {8,5.5, 7.3, 8.4}, "" };
    StudentGegevens Sinem {"Sinem Ertem",        19, {8,7.5, 7.3, 5.4}, "kat"};
    StudentGegevens Tim {"Tim Vermulen",                18, {5,7.5, 7.3, 5.4}, "Aap"};

    KlasGegevens V1N {"V1N", {Gijsbert, Sinem, Tim},    "Mr Heimans"};

    vector<KlasGegevens> klassenlijst = {V1N};

    string welkeklas;
    cout<< "Beschikbare klassen: ";
    for(KlasGegevens klas : klassenlijst){
        cout << klas.klasnaam << ' ';
    }
    cout << endl << "Van welke klas wil je het gemiddelde weten?: "; 
    cin >> welkeklas;
    
    for(KlasGegevens& klas : klassenlijst){
        if(welkeklas == klas.klasnaam){
            int count = 0;
            double total = 0;
            for(StudentGegevens& student : V1N.studentenlijst){
                for(double cijfer : student.cijferlijst){
                    total += cijfer;
                    count ++;
                }
            }
        double gemiddelde = total/count;
        cout<<"Klas "<< klas.klasnaam <<" heeft als gemiddelde: "<<setprecision(2)<<gemiddelde;
        }
    }
}