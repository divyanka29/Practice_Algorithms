#include <iostream>
#include <queue>

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


bool checkTreeEquality(Node*T1, Node*T2)
{
	if(T1 == NULL && T2 == NULL)
	{
		return true;
	}
	if(T1 == NULL && T2 == NULL && T1->data != T2->data)
	{
		return false;
	}
	return checkTreeEquality(T1->left, T2->left) && checkTreeEquality(T1->right, T2->right);
}

void checkSubtree(Node * T1, Node * T2)
{
	if(T2 == NULL)
	{
		std::cout << "Is a subtree\n";
		return;
		 //An emptry tree is always a subtree
	}
	if(T1 == NULL)
	{
		std::cout << "Not a subtree\n";
		return;
	}
	auto temp = T1;
	std::queue<Node*> q;
	q.push(temp);
	while(!q.empty())
	{
		temp = q.front();
		if(temp->data == T2->data)
		{
			if(checkTreeEquality(temp, T2))
			{
				std::cout << "Is a subtree\n";
				return;
			}
		}

		if(temp->left !=NULL) q.push(temp->left);
		if(temp->right !=NULL) q.push(temp->right);
		q.pop();
	}
	std::cout << "Not a subtree\n";
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
	auto T1 = new Node(20);
	auto T2 = new Node(2);
	buildT1(T1);
	buildT2(T2);
	checkSubtree(T1, T2);
	return 0;
}