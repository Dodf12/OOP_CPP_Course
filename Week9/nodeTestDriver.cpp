#include "node.h"
#include <iostream>

using namespace std;

int main()
{
	node* node1 = new node(1,nullptr);
	node* node2 = new node(2, nullptr);
	node* node3 = new node(3, nullptr);
	list_insert_head(node1, node2, 2);
	list_insert_tail(node1, node2, 3);
	cout << node1 << endl;



}