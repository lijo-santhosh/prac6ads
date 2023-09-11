#include "LinkedList.h"

#include <iostream>

LinkedList::LinkedList() { head = nullptr; }

LinkedList::LinkedList(int* array, int len) {}

LinkedList::~LinkedList() {
  while (head != nullptr) {
    if (head == nullptr) {
      return;
    }

    Node* temp = head;
    head = head->get_Link();
    delete temp;
  }
}

void LinkedList::insertPosition(int pos, int newNum) {
    Node* newNode = new Node(newNum);
  if (pos <= 1 || head == nullptr) {
    newNode->set_Link(head);
    head = newNode;
  }
  else {
    Node* current = head;
    for (int i = 1; i < pos - 1 && current->get_Link() != nullptr; i++) {
      current = current->get_Link();
    }
    newNode->set_Link(current->get_Link());
    current->set_Link(newNode);
  }
}

bool LinkedList::deletePosition(int pos) {
  if (pos <= 0) {
    return false;
  }
  if (head == nullptr) {
    return false;
  }

  if (pos == 1) {
    Node* temp = head;
    head = head->get_Link();
    delete temp;
    return true;
  }
return true;
}

int LinkedList::get(int pos) { return 0; }
int LinkedList::search(int target) { return 0; }

void LinkedList::printList() { return; }