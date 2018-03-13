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


void checkTreeEquality(Node*T1, Node*T2)
{
	
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
	assign(root, 41, 2);
	assign(root->left, 5, 11);//41
	assign(root->left->right, 2, -1);

	assign(root->right, 4, 2);//2
	assign(root->right->left, 2, -1);
	assign(root->right->left->left, 14, 12);
	assign(root->right->right, 9, 51);
	assign(root->right->right->right, 18, -1);
}

void buildT2(Node * root)
{
	assign(root, 9, 51);
	assign(root->right, 18, -1);
}

int main()
{
	return 0;
}