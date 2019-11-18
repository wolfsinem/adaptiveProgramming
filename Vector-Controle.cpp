#include <iostream> 
#include <vector> 
using namespace std; 
 
// g++ -std=c++17 Vector-Controle.cpp -o main
// ./main

bool VectorControle(const vector<bool>& controle){   
    int Aantal_True = 0;
    int Aantal_False = 0;
    for (bool a : controle){
        if(a){
            Aantal_True += 1;
        }
        else{
            Aantal_False += 1;
        }
    }
    return Aantal_True > Aantal_False && Aantal_False <= 12;

}

int main(){
    vector<bool> controle = {true,true,false,true,false,true,true,false,false};
    bool v = VectorControle(controle);
    if(v == true){
        cout << "Aantal True > Aantal False en Aantal False <= 12"<< endl << "True" ;
    }else{
        cout << "False";
    }
}
