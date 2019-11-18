#include <iostream> 
#include <iomanip>
using namespace std; 

class MoneyUtils{
    public:
    static int count;
    static void bedrag(string geldeenheid, double bedrag,int precision = 3){
        if(geldeenheid == "EUR"){
            geldeenheid = "e";
        }
        else if(geldeenheid == "USD"){
            geldeenheid = "u";
        }
        else{
            cout<< "geldeenheid onbekent";
        }
        
        std::setprecision(precision);
        cout<<geldeenheid<<" "<<bedrag<<endl;
        count ++;
    }
};

int MoneyUtils::count = 0;

int main(){
    MoneyUtils::bedrag("EUR",23.42234);
    MoneyUtils::bedrag("USD", 3.1431592, 1);
    cout << MoneyUtils::count;
}
