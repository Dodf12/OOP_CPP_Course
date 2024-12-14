// Name: Abhinav Pala
// File: node.cpp
// File Location: SCU coursework folder in CSCI 60 Folder
// Date: 11-20-24
// Collaborators: N/A
// Description: The implementation file of my node file

#include "node.h"

// overloaded << for debugging
ostream& operator<< (ostream &out, const node *head)
{
    if (head == nullptr)
        return out;              // base case: empty list
    out << head->data () << " "; // non-recursively output the data of the head
    return (out << head->link ()); // recursively output everything else
}

// MY WORK STARTS HERE---------------------------------------

// Recursively finds the nth element of the given sequence
int f1 (int n)
{
    // If function is less than 2, it should automatically be 1
    if (n < 2)
        {
            return 1;
        }
    else if (n == 2)
        {
            return 1 + n - 1;
        }

    else
        {
            // Will only recurse if n is greater than 2
            return f1 (n - 2) + n - 1;
        }
}

// Reverses the functions elements using recursion
void f2 (int *a, int first, int last)
{
    // Make sures function doesnt switch already-switched elements
    if (first >= last)
        {
            return;
        }

    // Switching elements
    int temp = a[first];
    a[first] = a[last];
    a[last] = temp;

    // Decrements index so can switch the other elements
    first++;
    last--;
    f2 (a, first, last);
}

// Converting array into linked list
void f3 (node *&head, node *&tail, int *a, int n)
{
    // Exits if no elements in array
    if (n == 0)
        {
            return;
        }

    // Checks if it is a null pointer
    if (head == nullptr)
        {
            // Make head and tail point to same area
            head = new node (a[n - 1], nullptr);
            tail = head;
        }

    // Adds new element at beggining
    else
        {
            head = new node (a[n - 1], head);
        }

    // Does a recursive call
    f3 (head, tail, a, n - 1);
}

// Deleting all element from a linked list
void f4 (node *&head, node *&tail)
{
    // Checking if head has reached the end of linked list and exiting
    if (head == tail)
        {
            head = nullptr;
            tail = nullptr;
            return;
        }
    else
        {
            // Storing next node so I wont loose location
            node *temp = head->link ();
            // Deleting dynamic memory
            delete head;

            // Pointing head pointer to the next node to be deleted
            head = temp;
            // Recursively calls until array is empty
            f4 (head, tail);
        }
}
