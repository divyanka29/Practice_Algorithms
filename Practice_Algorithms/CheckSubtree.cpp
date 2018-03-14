/*
Check SubTree : T1 and T2 are very large binary trees, with T1 much larger than T2
				Create an algorithm to determine if T2 is a subtree of T1.

Option 1 : Print out pre Order traversal of both trees with special character for NULL children
			Traversal of T2 should be a substring of T1.
			Time : O(T1.size + T2.size) Space : O(T1.size + T2.size)

Option 2 : Do a BFS in T1 and whenever the value is equal to head of T2 , check equality of the subtree of T1 with T2.
		   Time : Worst case O(T1.size*T2.size) because everytime we find an elemnt equal to root of T2, we equate it to T2.size
		   If on an average there are k element in T1 which are equal to root of T2 then complexity is O(k*T2.size). Also while checking
		   for equality we will return as soon as there is a single inequality found. So it wont search the entire T2.size.
		   And if the subtree is present we wont traverse the entire T1 tree as we return as soon as subtree is found
*/

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
	if(T1 == NULL || T2 == NULL || T1->data != T2->data)
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
	std::queue<Node*> q;
	q.push(T1);
	while(!q.empty())
	{
		auto temp = q.front();
		
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