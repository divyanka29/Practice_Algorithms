/*
Check whether a given tree is a binary search tree.  
*/
#include <iostream>

struct Node
{
	Node(int d):
	data(d),
	left(NULL),
	right(NULL)
	{
	}
	int data;
	Node* left;
	Node* right;
};


bool isBST(Node * root, int min, int max)
{
	if(root==NULL) return true;
	if(root->data > max) return false;
	if(root -> data < min) return false;
	return isBST(root->left, min, root->data) && isBST(root->right, root->data, max);
}

bool isBST(Node * root)
{
	if(root==NULL) return true;
	return isBST(root->left, INT_MIN, root->data) && isBST(root->right, root->data, INT_MAX);
}

void assign(Node* temp, int left, int right)
{
	if(left != -1)
	{
		temp->left = new Node(left);
	}
	if(right != -1)
	{
		temp->right = new Node(right);
	}
}

void buildT1(Node * root)
{
	assign(root, 20, 50);
	assign(root->left, 10, 25);//41
	assign(root->left->right, 23, -1);

	assign(root->right, -1, 70);//2
}

int main()
{
	Node * A = new Node(30);
	buildT1(A);
	if(isBST(A)) std::cout << "it is a BST\n";
	else std::cout << "it is not a BST\n";
	return 0;
}