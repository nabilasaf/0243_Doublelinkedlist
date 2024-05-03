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
          current = current->next; //step 1.e: mpve the current to the next node
        }

        newNode->next = current; //step 4: Make the next field of the new node point to current
        newNode->prev = previous; //step 5: Make the previous field of the new node point to previous

        if (current != NULL)
        {
            current->prev = newNode; //step 6: Make the previousfield of the current node point to the new node
        }
         if (previous != NULL)
         {
            previous->next = newNode; //step 7: Make the next field of the previous node point to the new node
         }
         else{
            //If previous is still NULL, it means newNode is now the first node
            START =newNode;
         }
    }
};

bool search(int rollNo, Node **previous, Node **current)
{
    *previous = NULL;
    *current = START;
    while (*current != NULL && (*current)->noMhs != rollNo)
    {
        *previous = *current;
        *current = (*current)->next;
    }
    return (*current != NULL);
}

void deleteNode()
{
    Node *previous, *current;
    int rollNo;

    cout << "\nEnter the roll number of the student whose record is to be delted: ";
    cin >> rollNo; //step 3: get the roll number to be deleted

    if (START == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }

     current = START; //step 1: start form the first node
     previous = NULL;

     // Locate the node to be deleted
     while (current != NULL && current->noMhs != rollNo)
     {
        previous = current;
        current = current->next;
     } 
     if (current == NULL)
     {
        cout << "\033[31mThe record with roll number " << rollNo << " not found\033[0m" << endl;
        return;
     }

     // Node to be deleted is the first node
     if (current == START)
     {
        START = START->next; //step 2: update the START pointer
        if (START != NULL)
        {
            START->prev = NULL;
        }
     }
     else
     {//Node to be deleted is not the first node
       previous->next = current->next;
       if (current->next != NULL)
       {// If there'sa successor, update its prev pointer
           current->next->prev = previous;
       }
     }

     //Release the memory of the node marked as current
     delete current;
     cout << "\x1b[32mRecord with roll number " << rollNo << "deleted\x1b[0m" << endl;
}

bool listEmpty()
{
    return (START = NULL);
}