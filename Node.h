#ifndef NODE_H
#define NODE_H

class Node {
 private:
  Node* link;
  int data;

  public:
  Node(int data);
  Node(int data, Node* link);
  Node* get_Link();
  void set_Link(Node* link);
};

#endif