#include "Node.h"

// Get next node
Node* Node::getNext() {
  return next;
}

// Get student from node 
Student* Node::getStudent() {
  return student;
}

// Set next node
void Node::setNext(Node* n) {
  next = n;
}

// Node constructor
Node::Node(Student* s) {
  student = s;
  next = nullptr;
}

// Node destructor
Node::~Node() {
  delete student; // Make sure we get rid of the student too 
}
