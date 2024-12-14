// Parity implementation starter file for CSCI 60 Homework 9; due Thursday
// 12/5/24

// Name: Abhinav Pala
// File: parity.cpp
// File Location: In my SCU folder Under Week 9
// Date: 11-14-2024
// Collaborators: 
// Description: Implementation file of parity.h

#include "parity.h" // Don't add any additional libraries/namespaces!

// MILESTONE 1: implement insert
void Parity::insert(int val)
{
    //Checking if number is even or odd
    if (val % 2 == 0)
        {
            list_insert_sorted(h_e, t_e, val);
            n_e++;
        }
    else
        {
            list_insert_sorted(h_o, t_o, val);
            n_o++;
        }
}
// MILESTONE 2: overload <<, and implement min and max
ostream& operator<<(ostream& out, const Parity& lists)
{
    //Looping through evens and outputting
    out << "Evens: ";
    for (node *curr = lists.h_e; curr != nullptr; curr = curr->link())
        {
            out << curr->data() << ", ";
        }

    out << std::endl;

    //Going through odd linked list
    out << "Odds: ";
    for (node *curr = lists.h_o; curr != nullptr; curr = curr->link())
        {
            out << curr->data() << ", ";
        }
    out << std::endl;
    return out;
}

/*Finds the smallest element in the linked list while accounting
for nullptrs*/
int Parity::min() const
{
    if (h_e == nullptr && h_o == nullptr)
        {
            return 0;
        }

    if (h_e == nullptr && h_o != nullptr)
        {
            return h_o->data();
        }
    if (h_o == nullptr && h_e != nullptr)
        {
            return h_e->data();
        }

    if (h_e->data() > h_o->data())
        {
            return h_o->data();
        }
    return h_e->data();
}

/*Finds the largest element in the linked list while accounting
for nullptrs*/
int Parity::max() const
{
    if (t_e == nullptr && t_o == nullptr)
        {
            return 0;
        }

    if (t_e == nullptr && t_o != nullptr)
        {
            return t_o->data();
        }
    if (t_o == nullptr && t_e != nullptr)
        {
            return t_e->data();
        }

    if (t_e->data() > t_o->data())
        {
            return t_e->data();
        }
    return t_o->data();
}
// MILESTONE 3: overload =, and implement a copy constructor and destructor

//Destructor deletes both linked lists and resets size variable
Parity::~Parity()
{
    //First delete even linked list
    node *curr = h_e;
    node *prev = h_e;
    while (curr != nullptr)
        {
            prev = curr;
            curr = curr->link();
            delete prev;
        }
    delete curr;
    h_e = nullptr;

    //Now deletes odd linked list
    curr = h_o;
    prev = h_o;
    while (curr != nullptr)
        {
            prev = curr;
            curr = curr->link();
            delete prev;
        }
    delete curr;
    h_o = nullptr;
    n_o = 0;
    n_e = 0;
}

//Copy Constructor
Parity::Parity(const Parity& other)
{
    // Creates new object's head node
    h_e = new node(other.h_e->data(), nullptr);

    // Uses two pointers to copy both the elements
    node *currEven = h_e;
    node *currOther = other.h_e->link();

    // Creates and appends new link at end of linked list
    while (currOther != nullptr)
        {
            currEven->set_link(new node(currOther->data(), nullptr));
            currEven = currEven->link();
            currOther = currOther->link();
        }
    // Set tail to last element and number to new number
    t_e = currEven;
    n_e = other.n_e;

    // Code is repeat of evens, but for odd
    h_o = new node(other.h_o->data(), nullptr);
    node *currOdd = h_o;
    node *currOddOther = other.h_o->link();

    while (currOddOther != nullptr)
        {
            currOdd->set_link(new node(currOddOther->data(), nullptr));
            currOdd = currOdd->link();
            currOddOther = currOddOther->link();
        }
    t_e = currOdd;
    n_o = other.n_o;

    //++++++
    // I changed it to O(n), this is my old solution
    //++++++

    // if (other.h_e == nullptr)
    //     {
    //         return;
    //     }
    // node *curr = other.h_e;
    // while (curr != nullptr)
    //     {
    //         insert (curr->data ());
    //         curr = curr->link ();
    //     }

    // if (other.h_o == nullptr)
    //     {
    //         return;
    //     }

    // curr = other.h_o;
    // while (curr != nullptr)
    //     {
    //         insert (curr->data ());
    //         curr = curr->link ();
    //     }


}

//Overloaded assignment operator
//Utilizes same logic as copy constructor
Parity& Parity::operator=(const Parity &rhs)
{
    if (this == &rhs)
        {
            return *this;
        }

    //Clears the left-hand side objects
    list_clear(h_e, t_e);
    list_clear(h_o, t_o);

    // Creates new node
    h_e = new node(rhs.h_e->data(), nullptr);

    // Uses two pointers to copy both the elements
    node *currEven = h_e;
    node *currOther = rhs.h_e->link();

    // Creates and appends new link at end of linked list
    while (currOther != nullptr)
        {
            currEven->set_link(new node(currOther->data(), nullptr));
            currEven = currEven->link();
            currOther = currOther->link();
        }
    // Set tail to last element and number to new number
    t_e = currEven;
    n_e = rhs.n_e;

    // Code is repeat of evens, but for odd
    h_o = new node(rhs.h_o->data(), nullptr);
    node *currOdd = h_o;
    node *currOddOther = rhs.h_o->link();

    while(currOddOther != nullptr)
        {
            currOdd->set_link(new node(currOddOther->data(), nullptr));
            currOdd = currOdd->link();
            currOddOther = currOddOther->link();
        }
    t_e = currOdd;
    n_o = rhs.n_o;

    return *this;
}
// MILESTONE 4: implement begin and end

//iterator begin
P_iterator Parity::begin() const
{
    return P_iterator(h_e, h_o);
}

//Iterator end
P_iterator Parity::end() const
{
    return P_iterator();
}
