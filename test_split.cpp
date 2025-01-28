/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <iostream>

using namespace std;

void list_print(Node* head) {
    while (head != nullptr)   {
        cout << head->value << ' ';
        head = head->next;
    }
    cout << endl;
}


int main(int argc, char* argv[])
{
    Node node6(6, nullptr);
    Node node5(5, &node6);
    Node node4(4, &node5);
    Node node3(3, &node4);
    Node node2(2, &node3);
    Node node1(1, &node2);
    Node* head = &node1;
    Node* evens = nullptr;
    Node* odds = nullptr;

    cout << "before split:";
    list_print(head);
    split(head, odds, evens);
    cout << "head:";    list_print(head);
    cout << "evens:";   list_print(evens);
    cout << "odds:";    list_print(odds);
    if(head == nullptr) {cout << "HEAD NULL" << endl;}


   return 0;
}
