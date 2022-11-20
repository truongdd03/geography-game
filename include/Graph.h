#ifndef GRAPH_H
#define GRAPH_H

#include <Node.h>

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Graph {
 private:
  void read();
  void dfs(Node *node, int depth);

 public:
  int depth = 0;
  Node *root = nullptr;
  vector<vector<string>> variablesByLevel = {};
  unordered_map<string, Node *> val_to_node = {};
  vector<string> values;

  void init();
};

using namespace std;

void Graph::read() {
  string root_val;
  cin >> root_val;
  root = new Node(root_val, nullptr, {});
  depth = 1;
  val_to_node[root_val] = root;

  string u, v;
  while (cin >> u >> v) {
    if (val_to_node.find(u) == val_to_node.end())
      throw invalid_argument(u + " is used before define");
    if (val_to_node.find(v) == val_to_node.end()) {
      val_to_node[v] = new Node(v, val_to_node[u], {});
    }
    val_to_node[u]->children.push_back(val_to_node[v]);
    depth = max(depth, int(val_to_node[u]->children.size() + 1));
  }

  for (auto e : val_to_node) {
    if (e.first != root_val) {
      values.push_back(e.first);
    }
  }
}

void Graph::init() {
  read();
  // Node *tmp = root;
  // dfs(tmp, 0);
}

#endif
