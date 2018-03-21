/*
Copy of Linked List
*/

#include <iostream>

struct Node
{
	int data;
	Node* next;

	Node(int data):
	data(data),
	next(NULL)
	{
	}
};


Node* copy(Node * root)
{
	if(root==NULL)
	{
		return NULL;
	}
	auto copyLL = new Node(root->data);
	auto copyTemp = copyLL;

	auto temp = root->next;
	while(temp != NULL)
	{
		copyTemp->next = new Node(temp->data);;
		temp=temp->next;
		copyTemp = copyTemp->next;
	}
	return copyLL;
}

int main()
{
	auto a = new Node(3);
	a->next = new Node(5);
	a->next->next = new Node(2);
	auto b = copy(a);
	auto t = b;
	while(t != NULL)
	{
		std::cout << t->data << "->";
		t=t->next;
	}
	std::cout <<"NULL\n";
	return 0;
}