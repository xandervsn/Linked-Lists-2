/* Uno (Wongspatt) Pasadhika 
 * Linked Lists (part 1) - student and node classes 
 * 1/17/2023 
 */

#include <iostream>
#include <cstring>
// Probably wanna include the student thingy too 

class Node {
 private:
  Student* student;
  Node* next;
 public:
  Node* getNext(); // Get pointer to next node
  Student* getStudent(); // Get pointer to student 
  void setNext(Node*); // Set next node pointer
  Node(Student*); // Constructor
  ~Node(); // Destructor 
};
