#include <operators.h>
#include <Node.h>

#include <fstream>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <stdexcept>

using namespace std;

Node *root;
unordered_map<string, Node *> val_to_node;

void read() {
  string root_val;
  cin >> root_val;
  write(root_val);
  root = new Node(root_val, {});
  val_to_node[root_val] = root;

  string u, v;
  while (cin >> u >> v) {
    if (val_to_node.find(u) == val_to_node.end()) throw invalid_argument(u + " is used before define");
    if (val_to_node.find(v) == val_to_node.end()) {
      val_to_node[v] = new Node(v, {});
    }
    val_to_node[u]->children.push_back(val_to_node[v]);
  }
}

void solve() {}

int main() {
  clear();
  write("#QCIR-G14\n");
  read();
  solve();
  return 0;
};