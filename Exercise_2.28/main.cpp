#include <iostream>
#include "states.hpp"
#include "statespace.hpp"

// g++ -std=c++17 main.cpp states.cpp statespace.cpp -o markov; ./markov

int main() {
  statespace space;
  ifstream inFile;
  inFile.open(
      "D:\\Workspaces\\Adaptive-Programming\\Exercise_2.28\\Parsing.txt");
  std::string str;
  while (std::getline(inFile, str)) {
    space.parsing(str);
  }
  inFile.close();
  for (int x = 0; x < 3; x++) {
    vector<string> statess;
    vector<int> waardes;
    state* initial{&space.states[0]};
    statess.push_back(initial->name);
    while (initial != &space.states[space.states.size() - 1]) {
      initial = initial->next();
      statess.push_back(initial->name);
      if (initial->waarde != 0) {
        auto it = waardes.insert(waardes.begin(), initial->waarde);
      }
    }
    if (initial == &space.states[space.states.size() - 1]) {
      string lastState = statess[statess.size() - 2];
      std::cout << "pad " << x + 1 << ":  ";
      for (int i = 0; i < statess.size() - 1; i++) {
        std::cout << statess[i] << " ";
      }
      std::cout << "\t\tuitkomst: s = " << lastState << ", d = " << waardes[0]
                << std::endl;
    }
  }
  return 0;
}
