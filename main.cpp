#include <iostream>
#include "node.h"

using namespace std;

Node* init();
void print(Node*);
void add(Node*, Node*);

int main() {
  Node* head = init();
  Node* n = head;

  while(true){
    cout << "Input command (ADD, DLT, PRINT, AVG, QUIT):" << endl;
    char input[80];
    cin >> input;

    if(strcmp(input, "ADD") == 0){
      //init first student
      cout << "First Name:" << endl;
      char* firstName = (char*)"thisis";
      //cin >> firstName;
      cout << "Last Name:" << endl;
      char* lastName = (char*)"atest";
      //cin >> lastName;
      cout << "ID:" << endl;
      int id = 0;
      cin >> id;
      cout << "GPA:" << endl;
      float gpa = 0.00;
      cin >> gpa;

      Node* newStudent = new Node(new Student((char*)firstName, lastName, id, gpa));
      add(head, newStudent);
    }else if(strcmp(input, "DLT") == 0){

    }else if(strcmp(input, "PRINT") == 0){
      print(head);
    }else if(strcmp(input, "AVG") == 0){

    }else if(strcmp(input, "QUIT") == 0){
      break;
    }
  }
    return 0;
}

void print(Node* n) {
  while (n != nullptr) {
    Student* s = n->getStudent();
    cout << s->firstname << ' ' << s->lastname << ' ' << s->id << ' ' << s->gpa << '\n';
    n = n->getNext();
  }
  cout << endl; // Flush output stream and add new line
}

void add(Node* current, Node* newStudent){
  if(current->getStudent()->id < newStudent->getStudent()->id){
    newStudent->setNext(current->getNext());
    current->setNext(newStudent);
    return;
  }

  if(current->getNext() != NULL){
    add(current->getNext(), newStudent);
  }else{
    newStudent->setNext(current->getNext());
    current->setNext(newStudent);
    return;
  }
}

Node* init(){
   //init first student
  cout << "First Name:" << endl;
  char* firstName1 = (char*)"thisis";
  //cin >> firstName1;
  cout << "Last Name:" << endl;
  char* lastName1 = (char*)"atest";
  //cin >> lastName1;
  cout << "ID:" << endl;
  int id1 = 0;
  cin >> id1;
  cout << "GPA:" << endl;
  float gpa1 = 0.00;
  cin >> gpa1;

  Node* newStudent = new Node(new Student((char*)firstName1, lastName1, id1, gpa1));
  newStudent->setNext(NULL);
  return newStudent;
}
