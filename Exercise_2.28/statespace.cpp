#include "statespace.hpp"

string statespace::zoek(string str, string finder, int p, int b, int c) {
  if (c != 0) {
    if (str.find(finder) < str.size()) {
      return str.substr(str.find(finder, c) + p, b);
    } else {
      return "Nope";
    }
  } else {
    if (str.find(finder) < str.size()) {
      return str.substr(str.find(finder) + p, b);
    } else {
      return "Nope";
    }
  }
}
void statespace::parsing(string str) {
  if (str.size() > 25) {
    string state = zoek(str, "s=", 2, 1);
    string kans1 = zoek(str, "->", 3, 3);
    string kans2 = zoek(str, "+", 2, 3);
    string nstate1 = zoek(str, "s'=", 3, 1);
    string nstate2 = zoek(str, "s'=", 3, 1, str.find("s'=") + 1);
    string onb_waarde1 = zoek(str, "d'=", 3, 1);
    string onb_waarde2 = zoek(str, "d'=", 3, 2, str.find("d'=") + 1);
    if (onb_waarde2.at(1) == ')') {
      onb_waarde2 = onb_waarde2.at(0);
    } else {
      onb_waarde2 = "nope";
    }
    if (onb_waarde1 == onb_waarde2) {
      onb_waarde2 = "nope";
    }
    string waarde1 = "nope";
    string waarde2 = "nope";

    if (nstate2 == "7") {
      waarde2 = onb_waarde2;
    }
    if (nstate1 == "7") {
      waarde1 = onb_waarde1;
    } else {
      if (nstate2 == "7") {
        waarde2 = onb_waarde1;
      }
    }

    if (std::stod(kans1) + std::stod(kans2) == 1) {
      if (waarde1 != "nope") {
        states[stoi(state)].add_transition({states[stoi(nstate1)], stod(kans1)},
                                           stoi(waarde1));
      } else {
        states[stoi(state)].add_transition(
            {states[stoi(nstate1)], stod(kans1)});
      }
      if (waarde2 != "nope") {
        states[stoi(state)].add_transition({states[stoi(nstate2)], stod(kans2)},
                                           stoi(waarde2));
      } else {
        states[stoi(state)].add_transition(
            {states[stoi(nstate2)], stod(kans2)});
      }
    } else {
      cout << "Kansen opgeteld zijn niet 100%" << endl;
    }
  } else {
    if (str.at(0) == 's' and str.at(1) == ' ') {
      string van = zoek(str, "[", 1, 1);
      string tot = zoek(str, "]", -1, 1);
      int vanaf = std::stoi(van);
      int totenmet = std::stoi(tot);
      for (int i = vanaf; i < totenmet + 1; i++) {
        state s{std::to_string(i)};
        states.push_back(s);
      }
      cout << endl;
    }
    if (str.at(0) == 's' and str.at(1) == '=') {
      string state = zoek(str, "s=", 2, 1);
      string nstate1 = zoek(str, "s'=", 3, 1);
      states[stoi(state)].add_transition({states[stoi(nstate1)], 1.0});
    }
  }
}
