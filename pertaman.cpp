#include <iostream>
#include <string>
using namespace std;

struct Node
{
    int noMhs;
    string name;
    Node* next;
    Node* prev;
};

Node* START = NULL;

void addNode() {
    Node* newNode = new Node();  //step1 : create a new node
    cout << "\nEnter the roll number of the student: ";
    cin >> newNode->noMhs;      // assign value to the data field of the new node
    cout << "\nEnter the name of the student: ";
    cin >> newNode->name;       // assign value to the data field of the new node

    // Insert teh new node in the list
    if (START == NULL || newNode->noMhs <= START->noMhs) {
        if (START != NULL && newNode->noMhs == START->noMhs)
        {//step2: insert the new node at the beginning
            cout << "\033[31mDuplicate roll nubers not allowed\033]0m" <<endl;
            return;
        }
        //If the list is empty, make the new node the START
        newNode->next = START;  //step3 : make the new node point to the first node
        if (START != NULL) {
            START->prev = newNode; //step4 : make the first node point to the new node
        }
        newNode->prev = NULL; //step5: make the new node point to NULL
        START = newNode;      //step6: make the new node the first node
    }
    else{
        //insert the new node in the middle or et the end
        Node *current = START; //step 1.a: start from the first node
        Node *previous = NULL; //step 1.b: previous node is NULL initially

        while (current != NULL && current->noMhs < newNode->noMhs)
        {                      //step 1.c: traverse teh list to find the correct position
          previous = current;  //step 1.d: move the previous to the current node
        }
    }
};

