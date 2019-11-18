#include "states.hpp"

#include <chrono>
#include <iostream>
#include <time.h>
using std::cout;

std::uniform_real_distribution<double> state::unif{0.1};
std::default_random_engine state::re(time(0));


state* state::next() {
  double arandom = unif(re);

  if (transitions.size() == 0) {
    return this;
  }

  // implement the discrete-time markov jump
  // (finds the next state)

  int i = -1;
  while (arandom > 0) {
    i++;
    arandom = arandom - transitions[i].probabiltiy;
    
  }
  return transitions.at(i).next;
}

ostream& operator<<(ostream& os, const state& rhs) {
  os << rhs.name<<" "<<rhs.waarde;
  return os;
}
