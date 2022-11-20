#ifndef NODE_H
#define NODE_H

#include <vector>
#include <string>

struct Node {
  std::string val;
  std::vector<Node *> children;

  Node(std::string const &val, std::vector<Node *> const &children) {
    this->val = val;
    this->children = children;
  }
};

#endif
