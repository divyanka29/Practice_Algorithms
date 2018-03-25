/*
Find the minimum distance to a leaf node in a binary tree.
*/

#include <iostream>

struct Node
{
	int value;
	Node * left;
	Node * right;
	Node(int value):
	value(value),
	left(NULL),
	right(NULL)
	{}
};


int min(int a , int b)
{
	if(a<=b) return a;
	return b;
}



int minDistance(Node* root)
{
	if(root ==NULL)
	{
		return INT_MAX;
	}
	if(root->left == NULL && root->right==NULL)
	{
		//std::cout << "Returning 1 for : " << root->value << "\n";
		return 1;
	}

	return  1+ min(minDistance(root->left), minDistance(root->right));
}

int main()
{
	Node * root = new Node(10);
	root->left = new Node(54);
	//root->left->left = new Node(5);
	root->left->right = new Node(4);
	root->left->right->right = new Node(8);
	root->right = new Node(9);
	root->right->right = new Node(15);
	root->right->right->right = new Node(18);
	std::cout << minDistance(root) << std::endl;

}