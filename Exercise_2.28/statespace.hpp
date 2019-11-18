#ifndef _STATESPACE_HPP
#define _STATESPACE_HPP
#include "states.hpp"
#include <fstream>

class statespace {    
 public:
  vector<state> states;
  vector<transition> transitions;
  string zoek(string str, string finder, int p, int b, int c = 0);
  void parsing(string str);
};

#endif  // _STATES_HPP