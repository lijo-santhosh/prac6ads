#include "Node.h"

Node::Node(int data, Node* link) {
    this->data = data;
    this->link = link;
}

Node* Node::get_Link() {
    return link;
}

void Node::set_Link(Node* link) {
    this->link = link;
}

Node::Node(int data) {
  this->data = data;
  link = nullptr;
}