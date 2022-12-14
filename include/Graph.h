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
  void dfs(string const &node, int h, unordered_map<string, bool> &visited);

 public:
  int depth = 0;
  string root;
  vector<string> values;
  unordered_map<string, unordered_map<string, bool>> edges;

  void init();

  vector<string> getChildren(string const &node);
  vector<string> getParents(string const &node);
};

using namespace std;

void Graph::dfs(string const &node, int h, unordered_map<string, bool> &visited) {
  if (visited.find(node) != visited.end()) return;
  visited[node] = true;

  vector<string> children = getChildren(node);
  depth = max(depth, h);
  for (auto c : children) {
    dfs(c, h + 1, visited);
  }
}

void Graph::read() {
  cin >> root;

  string u, v;
  while (cin >> u >> v) {
    edges[u][v] = 1;
    if (find(values.begin(), values.end(), u) == values.end() && u != root)
      values.push_back(u);
    if (find(values.begin(), values.end(), v) == values.end() && v != root)
      values.push_back(v);
  }
}

void Graph::init() { 
  read();
  unordered_map<string, bool> visited;
  dfs(root, 1, visited);
}

vector<string> Graph::getChildren(string const &node) {
  vector<string> children;
  for (auto e : edges[node]) {
    children.push_back(e.first);
  }
  return children;
}

vector<string> Graph::getParents(string const &node) {
  vector<string> parents;
  for (string const &u : values) {
    if (u == node) continue;
    if (edges[u].find(node) != edges[u].end()) {
      parents.push_back(u);
    }
  }
  return parents;
}

#endif
