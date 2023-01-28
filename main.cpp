#include <iostream>
#include "node.h"

using namespace std;

Node* init();
void print(Node*);
void add(Node*, Node*);
void dlt(Node*, int);
float average(Node*, float, float);

int main() {
  Node* head = init();

  while(true){
    cout << "Input command (ADD, DLT, PRINT, AVG, QUIT):" << endl;
    char input[80];
    cin >> input;

    if(strcmp(input, "ADD") == 0){
      //init first student
      cout << "First Name:" << endl;
      char first[80];
      cin >> first;
      cout << "Last Name:" << endl;
      char last[80];
      cin >> last;
      cout << "ID:" << endl;
      int id = 0;
      cin >> id;
      cout << "GPA:" << endl;
      float gpa = 0.00;
      cin >> gpa;

      Node* newStudent = new Node(new Student((char*)first, last, id, gpa));
      if(id < head->getStudent()->id){
        newStudent->setNext(head);
        head = newStudent;
      }else{
        add(head, newStudent);
      }
    }else if(strcmp(input, "DLT") == 0){
      if(head->getNext() == NULL){
        cout << "There is only 1 student in this list!" << endl;
      }else{
        int num = 0;
        cout << "ID of student to delete:" << endl;
        cin >> num;
        if(head->getStudent()->id == num){
          Node* nodeToDelete = head;
          head = head->getNext();
          delete nodeToDelete;
        }else{
          dlt(head, num);
        }
      }
    }else if(strcmp(input, "PRINT") == 0){
      print(head);
    }else if(strcmp(input, "AVG") == 0){
      //average(head, 0, 0);
      cout << "Average: " << average(head, 0, 0) << endl;
    }else if(strcmp(input, "QUIT") == 0){
      break;
    }
  }
    return 0;
}

float average(Node* current, float avg, float count){
  count++;
  avg = avg + current->getStudent()->gpa;
  //OAcout << "average:" << avg << endl;
  //cout << "count:" << count << endl;

  if(current->getNext() != NULL){
   average(current->getNext(), avg, count);
  }
  float result = avg/count;
  cout << result << endl;
  return 0;
}

void dlt(Node* current, int studentID){
  int currentID = current->getStudent()->id;
  int nextID = current->getNext()->getStudent()->id;
  cout << "yup" << endl;
  //if(nextID == studentID && current->getNext()->getNext() == NULL){
    //Node* nodeToDelete = current->getNext();
    //current->setNext(NULL);
    //delete nodeToDelete;
    //return;
  //}

  if(nextID == studentID){
    Node* nodeToDelete = current->getNext();
    current->setNext(nodeToDelete->getNext());
    delete nodeToDelete;
    return;
  }

  if(current->getNext() == NULL){
    return;
  }

  if(current->getNext() != NULL){
    dlt(current->getNext(), studentID);
  }else{
    return;
  }
}

void add(Node* current, Node* newStudent){
  int currentID = current->getStudent()->id;
  int studentID = newStudent->getStudent()->id;

  if(current->getNext() == NULL && studentID > currentID){
    current->setNext(newStudent);
    newStudent->setNext(NULL);
    return;
  }

  int nextID = current->getNext()->getStudent()->id;

  if(studentID > currentID && studentID < nextID){
    newStudent->setNext(current->getNext());
    current->setNext(newStudent);
    cout << "cond" << endl;
    return;
  }

  if(current->getNext() != NULL){
    add(current->getNext(), newStudent);
  }
}

void print(Node* current) {
  Student* s = current->getStudent();
  cout << s->firstname << ' ' << s->lastname << ' ' << s->id << ' ' << s->gpa << endl;

  if(current->getNext() != NULL){
      print(current->getNext());
  }
  return;
}

Node* init(){
   //init first student
  cout << "First Name:" << endl;
  char first1[80];
  cin >> first1;
  cout << "Last Name:" << endl;
  char last1[80];
  cin >> last1;
  cout << "ID:" << endl;
  int id1 = 0;
  cin >> id1;
  cout << "GPA:" << endl;
  float gpa1 = 0.00;
  cin >> gpa1;

  Node* newStudent = new Node(new Student((char*)first1, last1, id1, gpa1));
  newStudent->setNext(NULL);
  return newStudent;
}
