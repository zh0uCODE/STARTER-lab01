// intlist.cpp
// Implements class IntList
// Lucas Zhou, 12/29/2025

#include "intlist.h"

#include <iostream>
using std::cout;

// copy constructor
IntList::IntList(const IntList& source) {
  head = nullptr; //build from empty list
  if (source.head == nullptr) { //no source
    return; //exit
  }
  head = new Node; //override head, allocate memory (equiv. of create new node)
  head->info = source.head->info; //fill new node with source data
  head->next = nullptr; //next null
  Node* srcnext = source.head->next; //we want the next node of the source to be copied
  Node* curr = head; //track a current pointer starting at the head;
  while (srcnext != nullptr) { //the remaining nodes in the source have to be non null
    curr->next = new Node; //add a node
    curr = curr->next; //update the current pointer
    curr->info = srcnext->info; //assign data of next source node
    curr->next = nullptr; //arrow for curr
    srcnext = srcnext->next; //move to the next node in source
  } 
}

// destructor deletes all nodes
IntList::~IntList() {
    Node* n = head; //set up tracker
    while (n != nullptr) { //while n is not null
      Node* next = n->next; //save next one
      delete n; //delete NODE before (pointer is not deleted)
      n = next; //update n POINTER
    }
}


// return sum of values in list
int IntList::sum() const {
    Node* n = head; //starting point
    int sum = 0; //sum is initially zero
    while (n != nullptr) { //as long as tracker n is null
      sum += n->info; //add the info
      n = n->next; //move n by one node
    } 
    return sum; //return the sum!
}


// returns true if value is in the list; false if not
bool IntList::contains(int value) const {
    Node* n = head; //start at head for n tracker
    while (n != nullptr) { //while n isn't null
      if (n->info == value) { //value must equal current node's val (first check)
        return true; //true
      }
      n = n->next; //if not, move
    }
    return false; //value isn't in list after traversing
}

// returns maximum value in list, or 0 if empty list
int IntList::max() const {
  int max = 0; //initialize max to the lowest possible min
  Node* n = head; //head tracker
  while (n != nullptr) { //n must not be null
    if (n->info > max) { //check if the current value is bigger than the int max
      max = n->info; //update max if you find a n value bigger than int min
    }
    n = n->next; //move n
  }
  return max; //return the max
}

// returns average (arithmetic mean) of all values, or
// 0 if list is empty
double IntList::average() const {
  double sum = 0.0; //init sum variable
  double len = 0.0; //init len number of elements
  Node* n = head; //node n at the head
  while (n != nullptr) { //n needs to exist
    sum += n->info; //add the n infos to the sum variable (total)
    len++; //increase length by one
    n = n->next; //move n forward by one node
  }
  if (len == 0.0) { //zero length
    return 0.000; //return number as given
  }
  return sum / len; //the average is the sum over the length
}

// inserts value as new node at beginning of list
void IntList::push_front(int value) { 
  Node* newNode = new Node; //make new node
  newNode->info = value; //give the new node a value
  newNode->next = head; // point the next pointer to the head
  head = newNode; //update head with the newNode
}




// append value at end of list
void IntList::push_back(int value) {
  if (head == nullptr) { //head is null
    head = new Node; //head is new node
    head->info = value; //the value
    head->next = nullptr; //next is null
    return; //exit early since you only have one element
  }
  Node* n = head; //n is set at the head
  while (n->next != nullptr) { //keep going until n->next is null
    n = n->next; //keep moving n 
  }
  n->next = new Node; //save next as new node
  n->next->info = value; //give the next node a value
  n->next->next = nullptr; //added tail after is a null
}


// return count of values
int IntList::count() const {
  Node* n = head; //n is set to the head
  int count = 0; //count is zero initially
  while (n != nullptr) { //n is not null
    count++; //first add the count
    n = n->next; //move n next one node
  }
  return count; //return that count variable
}



//Assignment operator should copy the list from the source
//to this list, deleting/replacing any existing nodes
IntList& IntList::operator=(const IntList& source){
  if (this == &source) { //object self assignment has same reference
    return *this; //return the object
  }
  while (head != nullptr) { //head needs to exist
    Node* temp = head; //head pointer has temp variable
    head = head->next; //saved (head)
    delete temp; //delete the node before head
  } 
  if (source.head == nullptr) { //source is empty?
    head = nullptr; //set head to null (actual object, not source)
    return *this; //return the object!
  }
  head = new Node; //override head with new node (blank);
  head->info = source.head->info;// head info starts at the head of the source
  head->next = nullptr; //next pointer to null
  Node* curr = head; //current pointer at the head:
  Node* srcnext = source.head->next; //start the "next" node after the head of the source
  while (srcnext != nullptr) { //source's nexts need to exist
    curr->next = new Node; //update current pointer's next node with a new node
    curr->next->info = srcnext->info; //give the next node a value
    curr = curr->next; //move curr pointer by one
    srcnext = srcnext->next; //move srcnext over one node
  }
  return *this; //return the recreated object!
}


// constructor sets up empty list
IntList::IntList(){ 
  head = nullptr; //head nullptr is empty list
}


// DO NOT CHANGE ANYTHING BELOW (READ IT THOUGH)

// print values enclose in [], separated by spaces
void IntList::print() const {
    Node *n = head;
    cout << '[';
    while (n) {
        cout << n->info;
        if (n->next)
            cout << " ";
        n = n->next;
    }
    cout << ']';
}
