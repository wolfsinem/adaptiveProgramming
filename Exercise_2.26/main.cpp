#include <iostream>
#include "states.hpp"

//cd Desktop/Adaptive-Programming/Exercise_2.26/
//open main.cpp

//g++ -std=c++17 main.cpp states.cpp -o main
//./main

int main() {

  state s0("0");
  state s1("1");
  state s2("2");
  state s3("3");
  state s4("4");
  state s5("5");
  state s6("6");
  state s7("7");  

  s0.add_transition({s1, 0.5});  
  s0.add_transition({s2, 0.5});
  s1.add_transition({s3, 0.5});
  s1.add_transition({s4, 0.5});
  s2.add_transition({s5, 0.5});
  s2.add_transition({s6, 0.5});
  s3.add_transition({s1, 0.5}); 
  s3.add_transition({s7, 0.5},1); //1
  s4.add_transition({s7, 0.5},2); //2
  s4.add_transition({s7, 0.5},3); //3
  s5.add_transition({s7, 0.5},4); //4
  s5.add_transition({s7, 0.5},5); //5
  s6.add_transition({s2, 0.5});
  s6.add_transition({s7, 0.5},6); //6
  s7.add_transition({s7, 1});

  for(int x = 0; x < 3; x++){
  vector<string> states;
  vector<int> waardes;
  // print a path
  state* initial{&s0};
  states.push_back(initial->name);
  // std::cout << (*initial) << std::endl;

  while (initial != &s7) {
    initial = initial->next();
    states.push_back(initial->name);
    if(initial->waarde != 0){
      auto it = waardes.insert(waardes.begin(),initial->waarde);
    }
    // std::cout << (*initial) << std::endl;
  }
  if(initial == &s7){
    string lastState=states[states.size()-2];
    std::cout<<"pad "<<x+1<<":  ";
    for(int i = 0; i <states.size()-1;i++){
    std::cout<<states[i]<<" ";}
    std::cout<<"\t\tuitkomst: s = "<<lastState<<", d = "<<waardes[0]<<std::endl;
  }}
  return 0;
}
