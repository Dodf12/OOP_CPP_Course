// Name: Abhinav Pala
// File: node.cpp
// File Location: In my SCU folder Under Week 9
// Date: 11-14-2024
// Collaborators: N/A
// Description: Implementation file of node.h

#include "node.h" // Don't add any additional libraries/namespaces!

// overloaded << to print entire list
ostream& operator <<(ostream& out, const node * head) {
  if (head==nullptr) return out;
  return out << head->data() << ", " << head->link();
}

// iterates through list, keeping track of and then returning # nodes
size_t list_size(const node* head) {
  if (head==nullptr) return 0;
  return 1+list_size(head->link());
}

// iterates through list and returns true if given val is found, false otherwise
bool list_search(const node* head, int val) {
  if (head==nullptr) return false;
  if (head->data()==val) return true;
  return list_search(head->link(),val);
}

// deletes all nodes associated with a list and sets head and tail to null
void list_clear(node*& head, node*& tail) {
  node* next;
  while (head!=nullptr) {
    next=head->link();
    delete head;
    head=next;
  }
  tail=nullptr;
}

// inserts a node with specified value at the head (beginning/front) of a list
void list_insert_head(node*& head, node*& tail, int val) {
  head = new node(val,head);
  if (tail==nullptr) tail = head;
}

// inserts a node with specified value at the tail (end/back) of a list
void list_insert_tail(node*& head, node*& tail, int val) 
{
  node *temp = new node(val,nullptr);
  if (tail==nullptr) 
  {
    head = tail = temp;
  } 
  else
  {
    tail->set_link(temp);
    tail = tail->link();
  }
}


// MILESTONE 1: implement list_insert_sorted
//MY CODE STARTS HERE----------------------------
void list_insert_sorted(node*& head, node*& tail, int val)
{

  //Creates node and check if the head is a nullptr
  node* newNode = new node(val,nullptr);
  if (head == nullptr || head->data() > val)
  {
    newNode->set_link(head);
    head = newNode;
    return;
  }

  //Going through the nodes to find place for new node
  node* curr = head;
  node* prev = nullptr; //Stores the previous node
  while ((curr != nullptr) && curr->data() < val)
  {
    prev = curr;
    curr = curr->link();
  }

  //Changes the previous node
  newNode->set_link(curr);
  prev->set_link(newNode);

  //Checking if the number has been added to end of list

  if (newNode->link() == nullptr) { tail = newNode; }

}