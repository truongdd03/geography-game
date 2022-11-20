#include <Graph.h>
#include <operators.h>

#include <fstream>
#include <iostream>
#include <stdexcept>
#include <unordered_map>
#include <vector>

using namespace std;

int variable = 100;  // Start at 100

string get() { return to_string(variable++); }

vector<string> getMultiple(int cnt) {
  vector<string> vt;
  for (int i = 0; i < cnt; ++i) {
    vt.push_back(to_string(variable + i));
  }
  variable += cnt;
  return vt;
}

void headings(Graph const &g) {
  write("#QCIR-G14\n");
  vector<string> even, odd;
  for (int i = 1; i <= g.depth; ++i) {
    if (i % 2 == 0) {
      for (auto e : g.values) {
        even.push_back(to_string(i) + e);
      }
    } else {
      for (auto e : g.values) {
        odd.push_back(to_string(i) + e);
      }
    }
  }
  Exists(odd);
  Forall(even);
  write("output(999)");
}

// Exactly one node is chosen at each step
string condition1(Graph const &g) {
  write("\n\n");
  // At least 1 node is chosen at every step
  // (11 v 12 v ...) ^ (21 v 22 v ...) ^ ...
  string const subCondition1 = get();
  vector<string> vars = getMultiple(g.depth);
  for (int i = 1; i <= g.depth; ++i) {
    vector<string> vvars;
    for (auto e : g.values) {
      vvars.push_back(to_string(i) + e);
    }
    Or(vars[i - 1], vvars);
  }
  And(subCondition1, vars);

  write("\n");

  // No two nodes are chosen at the same step
  // (-11 v -12) ^ (-11 v -13) ^ ... ^ (-21 v -22) ^ (-21 v -23) ^ ...
  string const subCondition2 = get();
  vars = getMultiple(g.depth * (g.values.size() - 1));
  for (int d = 1; d <= g.depth; ++d) {
    string const tmp = "-" + to_string(d) + g.values[0];
    int index = (d - 1) * (g.values.size() - 1);
    for (int i = 1; i < g.values.size(); ++i) {
      Or(vars[index + i - 1], {tmp, "-" + to_string(d) + g.values[i]});
    }
  }
  And(subCondition2, vars);

  write("\n");
  string const condition = get();
  And(condition, {subCondition1, subCondition2});
  return condition;
}

//
string condition2(Graph const &g) { write("\n\n"); }

// Step (i-1)-th must be adjacent to step i-th
string condition3(Graph const &g) { 
  write("\n\n");
  
}

// First step must be adjacent to root
// (11 V 12 V 13 ...)
string condition4(Graph const &g) {
  write("\n\n");
  string const condition = get();
  vector<string> vars;
  for (auto node : g.root->children) {
    vars.push_back("1" + node->val);
  }
  Or(condition, vars);
  return condition;
}

void solve() {
  Graph g;
  g.init();

  headings(g);
  vector<string> vars = {condition1(g), condition4(g)};

  write("\n\n");
  And("999", vars);
}

int main() {
  clear();
  solve();
  return 0;
};