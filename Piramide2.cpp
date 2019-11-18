#include <iostream>
using namespace std; 

int main() {
    int x = 9;
    cout << "Hoe Groot? ";
    cin >> x;
    for(int i = 1; i <=x; i++){
        cout << string(x-i, ' ')<< string(i, '*')<<endl; 
    }
    for(int i = x-1; i > 0; i--){
        cout << string(x-i, ' ')<< string(i, '*')<<endl; 
    }
    return 0;
}