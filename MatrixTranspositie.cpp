#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void print(vector<vector<int>> x) {
  for (int i = 0; i < x.size(); i++) {
    for (int j = 0; j < x[i].size(); j++) {
      cout << x[i][j] << ' ';
    }
    cout << endl;
  }
}

void MatrixTranspositie(vector<vector<int>> &x) {
  for (int i = 0; i < x.size(); i++) {
    for (int j = 0; j <= i; j++) {
      swap(x[i][j], x[j][i]);
    }
  }
}

main() {
  vector<vector<int>> x;
  x = {{0, 1, 2}, {3, 4, 5}, {6, 7, 9}};
  x = {{0, 1, 2, 3}, {4, 5, 6, 7}, {8, 9, 10, 11}, {12, 13, 14, 15}};
  print(x);
  cout << endl;
  MatrixTranspositie(x);
  print(x);
}
