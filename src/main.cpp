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
        even.push_back(to_string(i) + e);
      }
    }
  }
  // Exists(odd);
  Exists(even);
  write("output(999)\n");
}

// Exactly one node is chosen at each step
string condition1(Graph const &g) {
  write("\n#Condition 1\n");
  // At least 1 node is chosen at every step
  // (11 v 12 v ...) ^ (21 v 22 v ...) ^ ...
  vector<string> vars = getMultiple(g.depth);
  // for (int i = 1; i <= g.depth; ++i) {
  //   vector<string> vvars;
  //   for (auto e : g.values) {
  //     vvars.push_back(to_string(i) + e);
  //   }
  //   Or(vars[i - 1], vvars);
  // }
  // string const subCondition1 = get();
  // And(subCondition1, vars);

  // write("\n");

  // No two nodes are chosen at the same step
  // (-11 v -12) ^ (-11 v -13) ^ ... ^ (-21 v -22) ^ (-21 v -23) ^ ... ^ (-12 v
  // -13) ^ (-12 v -14) ^ ...
  vars.clear();
  for (int d = 1; d <= g.depth; ++d) {
    for (int i = 0; i < g.values.size(); ++i) {
      string const tmp = "-" + to_string(d) + g.values[i];
      int index = (d - 1) * (g.values.size() - 1);
      for (int j = i + 1; j < g.values.size(); ++j) {
        vars.push_back(get());
        Or(vars.back(), {tmp, "-" + to_string(d) + g.values[j]});
      }
    }
  }
  string const subCondition2 = get();
  And(subCondition2, vars);

  write("\n");
  string const condition = get();
  // And(condition, {subCondition1, subCondition2});
  return subCondition2;
}

// Step i-th must not be visited before
// (-11 v -21) ^ (-12 v -22) ^ ... ^ (-21 v -31) ^ (-22 v -32) ^ ...
string condition2(Graph const &g) {
  write("\n#Condition 2\n");
  vector<string> vars;
  for (int i = 1; i < g.depth; ++i) {
    for (auto val : g.values) {
      vars.push_back(get());
      Or(vars.back(), {"-" + to_string(i) + val, "-" + to_string(i + 1) + val});
    }
  }

  string const condition = get();
  And(condition, vars);
  return condition;
}

// Step i-th must be adjacent to step (i+1)-th
string condition3(Graph &g) {
  write("\n#Condition 3\n");
  vector<string> vars;
  for (int i = 1; i < g.depth; ++i) {
    for (auto node : g.values) {
      vector<string> children = g.getChildren(node);
      if (children.size() == 0) continue;
      for (string &child : children) child = to_string(i + 1) + child;

      children.push_back("-" + to_string(i) + node);
      vars.push_back(get());
      Or(vars.back(), children);
    }
  }
  string const condition = get();
  And(condition, vars);
  return condition;
}

// First step must be adjacent to root
// (11 V 12 V 13 ...)
string condition4(Graph &g) {
  write("\n#Condition 4\n");
  vector<string> vars;
  for (string const &node : g.getChildren(g.root)) {
    vars.push_back("1" + node);
  }
  string const condition = get();
  Or(condition, vars);
  return condition;
}

// Winning condition
string condition5(Graph &g) {
  write("\n#Condition 5\n");
  vector<string> vars;
  for (int i = 1; i < g.depth; i += 2) {
    // (i1 v i2 v ...) ^ -(i+1)1 ^ -(i+1)2 ^ ... ^ -(i+2)1 ^ ...
    vector<string> tmp = g.values;
    for (string &e : tmp) e = to_string(i) + e;
    string const subCondition = get();
    Or(subCondition, tmp);

    vector<string> tmp1;
    for (int j = i + 1; j <= g.depth; ++j) {
      for (string const &e : g.values) {
        tmp1.push_back("-" + to_string(j) + e);
      }
    }
    tmp1.push_back(subCondition);

    vars.push_back(get());
    And(vars.back(), tmp1);
  }
  string const condition = get();
  Or(condition, vars);
  return condition;
}

// Step i-th must be adjacent to step (i-1)-th
string condition6(Graph &g) {
  write("\n#Condition 6\n");
  vector<string> vars;
  for (int i = 2; i <= g.depth; ++i) {
    for (auto node : g.values) {
      vector<string> parents = g.getParents(node);
      if (parents.size() == 0) continue;
      for (string &parent : parents) parent = to_string(i - 1) + parent;

      parents.push_back("-" + to_string(i) + node);
      vars.push_back(get());
      Or(vars.back(), parents);
    }
  }
  string const condition = get();
  And(condition, vars);
  return condition;
}

void solve() {
  Graph g;
  g.init();

  headings(g);
  vector<string> vars = {condition1(g), condition2(g), condition3(g),
                         condition4(g), condition5(g), condition6(g)};

  write("\n\n");
  And("999", vars);
}

int main() {
  clear();
  solve();
  return 0;
};