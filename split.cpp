/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/
#include <iostream>
#include "split.h"

using namespace std;

/* Add a prototype a helper function here if you need */
void append(Node*& n, int val);


void split(Node*& in, Node*& odds, Node*& evens)
{
  /* Add code here */
  if (in == NULL) {
    return;
  }
  int x = in->value;
  if (x%2) {
    append(odds, x);
  }else {
    append(evens, x);
  }

  //move to next node
  Node* tmp = in;
  in = in->next;
  delete tmp;

  split(in, odds, evens);
}

/* If you needed a helper function, write it here */
void append(Node*& n, int val) {
  if (n == NULL) {
    n = new Node(val, NULL);
  }else {
    Node* tmp = n;
    n = new Node(val, tmp);
  }
}