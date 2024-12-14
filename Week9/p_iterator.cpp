// Iterator implementation file for CSCI 60 Homework 9; CSCI 60 Homework 9; due
// Thursday 12/5/24

// Name: Abhinav Pala
// File: p_iterator.cpp
// File Location: In my SCU folder Under Week 9
// Date: 11-14-2024
// Collaborators: Collaborated with friend Kevin on
    /*
        Collaborated with friend Kevin on overloading
        < and >. Discussed logic to create functio
        and independently developed ouur own code
    */
// Description: Implementation file of p_iterator.h

#include "p_iterator.h"

// MILESTONE 4: Implement your P_iterator member functions here

//Constructor

//Line tabbed for 80 character per line limit
P_iterator::P_iterator(node *curr_e, node *curr_o) 
: curr_e(curr_e), curr_o(curr_o){}

// Dereference operator
int P_iterator::operator*() const
{
    // Check to make sure not nullpter
    if (curr_o == nullptr)
        {
            return curr_e->data();
        }
    if (curr_e == nullptr)
        {
            return curr_o->data();
        }

    if ((curr_e->data() < curr_o->data()))
        {
            return curr_e->data();
        }
    else
        {
            return curr_o->data();
        }
}

bool P_iterator::operator!=(const P_iterator& rhs) const
{
    if (curr_e != rhs.curr_e || curr_o != rhs.curr_o)
        {
            return true;
        }
    return false;
}

// This is the prefix ++
P_iterator& P_iterator::operator++()
{
    // Makes sure not to dereference nullptr

    // Line tabbed to meet 80 character requirement
    if (curr_e != nullptr
        && (curr_o == nullptr || curr_e->data() <= curr_o->data()))
        {
            curr_e = curr_e->link();
        }
    else if (curr_o != nullptr)
        {
            curr_o = curr_o->link();
        }
    return *this;
}

// EXTRA CREDIT STARTS HERE ++++++++++++++++++++

// Postfix ++
P_iterator P_iterator::operator++(int)
{
    node *temp1 = curr_e;
    node *temp2 = curr_o;

    // Line tabbed to meet 80 character requirement
    if (curr_e != nullptr
        && (curr_o == nullptr || curr_e->data() <= curr_o->data()))
        {
            curr_e = curr_e->link();
        }
    else if (curr_o != nullptr)
        {
            curr_o = curr_o->link();
        }

    return P_iterator(temp1, temp2);
}

bool P_iterator::operator==(const P_iterator& rhs) const
{
    if (*this == rhs)
        {
            return true;
        }
    return false;
}

bool P_iterator::operator<(const P_iterator& rhs) const
{
    // First find out of tails are equal of the iterator it is pointing too
    node *lhs_node = nullptr;
    node *rhs_node = nullptr;

    if (curr_e != nullptr)
        {
            lhs_node = curr_e;
        }
    else
        {
            lhs_node = curr_o;
        }

    if (rhs.curr_e != nullptr)
        {
            rhs_node = rhs.curr_e;
        }
    else
        {
            rhs_node = rhs.curr_o;
        }

    if (lhs_node == rhs_node)
        {
            /*
            If the nodes are the same, they are from the same Parity object
            This means they are pointing to the same node, so
            they cannot be less than each other
            */
            return false;
        }

    int lhsData = **this;
    int rhsData = *rhs;

    if (lhsData < rhsData)
        {
            return true;
        }

    return false;
}

bool P_iterator::operator>(const P_iterator& rhs) const
{
    // First find out of tails are equal of the iterator it is pointing too
    node *lhs_node = nullptr;
    node *rhs_node = nullptr;

    if (curr_e != nullptr)
        {
            lhs_node = curr_e;
        }
    else
        {
            lhs_node = curr_o;
        }

    if (rhs.curr_e != nullptr)
        {
            rhs_node = rhs.curr_e;
        }
    else
        {
            rhs_node = rhs.curr_o;
        }

    if (lhs_node == rhs_node)
        {
            /*
            If the nodes are the same, they are from the same Parity object
            This means they are pointing to the same node, so
            they cannot be less than each other
            */
            return false;
        }

    int lhsData = **this;
    int rhsData = *rhs;

    if (lhsData > rhsData)
        {
            return true;
        }

    return false;
}
