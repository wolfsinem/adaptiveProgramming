#ifndef _STATES_HPP
#define _STATES_HPP
using namespace std;
#include <iostream>
#include <random>
#include <string>
#include <vector>

using std::vector, std::string, std::ostream;

class state;

struct transition {
  state* next;
  double probabiltiy;
  transition(state& next, double prob) : next(&next), probabiltiy(prob){};
};

class state {
  static std::uniform_real_distribution<double> unif;
  static std::default_random_engine re;

 public:
  string name;
  int waarde;
  vector<string> lst;
  vector<transition> transitions;
  state(string name = "", vector<transition> t = {})
      : name(name), transitions(t){};
  state* next();
  void add_transition(const transition& t,int d=0){ transitions.push_back(t); waarde = d;};
  // if you use duplicate names for states, they will equate one other.
  bool operator==(const state& rhs) const { return !name.compare(rhs.name); };
  friend ostream& operator<<(ostream& os, const state& rhs);
};

#endif  // _STATES_HPP