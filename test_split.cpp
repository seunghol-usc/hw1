/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/
#include <iostream>
#include "split.h"

using namespace std;

void append(Node*& n, int val);
void split(Node*& in, Node*& odds, Node*& evens);
// void print_list(Node* n);

int main(int argc, char* argv[])
{
  Node* in = new Node(5, NULL);
  for (int i = 4; i > 0; i--) {
    Node* tmp = in;
    in = new Node(i, tmp);
  }

  Node* odds = NULL;
  Node* evens = NULL;
  split(in, odds, evens);

  // cout << "in = ";
  // print_list(in);

  // cout << "odds = ";
  // print_list(odds);

  // cout << "evens = ";
  // print_list(evens);

  while (odds != NULL) {
    Node* tmp = odds;
    odds = odds->next;
    delete tmp;
  }

  while (evens != NULL) {
    Node* tmp = evens;
    evens = evens->next;
    delete tmp;
  }
}
