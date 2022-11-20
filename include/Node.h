#ifndef NODE_H
#define NODE_H

#include <vector>
#include <string>

struct Node {
  std::string val;
  Node* parent;
  std::vector<Node *> children;

  Node(std::string const &val, Node *parent, std::vector<Node *> const &children) {
    this->val = val;
    this->parent = parent;
    this->children = children;
  }
};

#endif
