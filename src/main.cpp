#include <operators.h>

#include <fstream>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

struct Node {
  int val;
  vector<Node *> children;

  Node(int val, vector<Node *> const &children) {
    this->val = val;
    this->children = children;
  }
};

Node *root;
unordered_map<int, Node *> val_to_node;

void read() {
  int root_val;
  cin >> root_val;
  root = new Node(root_val, {});

  int u, v;
  while (cin >> u >> v) {
  }
}

void solve() {}

int main() {
  write("#QCIR-G14\n");
  solve();
  return 0;
};