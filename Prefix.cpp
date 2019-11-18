#include <iostream> 
using namespace std; 
  
bool prefix(const string& a, const string& b){
    int count = 0;
    for (char ac : a){
        char bc = b.at(count);
        if(ac == bc ){
            // cout << ac << endl;
            count += 1;
        }else{
            return false;
        }
    }
    return true;
}

int main(){
    string a("sterrrrr");
    string b("sterk");
    bool c = prefix(a,b);
    if(c == true){
        cout << "t is een prefix";
    }else{
        cout << "t is geen prefix";
    }
}