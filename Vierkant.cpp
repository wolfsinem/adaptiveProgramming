#include <iostream> 
#include <vector> 
using namespace std; 
  
int main(){
    int c;
    cout << "Hoe Groot? ";
    cin >> c;
    cout << "\n";
    int x = c;
    while(x > 0){
        int y = c;
        while(y > 0){
            cout << "*";
            y -= 1;
        }
        cout << endl;
        x -= 1;
    }
}