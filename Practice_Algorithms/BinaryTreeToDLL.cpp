/*
Given a binary tree(not a binary search tree), create a doubly linked, circular link list with data in the same order as the In Order transversal of the tree.
*/

#include <iostream>

struct TreeNode
{
	int value;
	TreeNode * left;
	TreeNode * right;
	TreeNode(int value):
	value(value),
	left(NULL),
	right(NULL)
	{}
};

struct LLNode
{
	int value;
	LLNode * prev;
	LLNode * next;
	LLNode(int value):
	value(value),
	prev(NULL),
	next(NULL)
	{}

	LLNode(int value, LLNode* prev):
	value(value),
	prev(prev),
	next(NULL)
	{}
};

void printLL(LLNode * root)
{
	auto temp = root;
	while(temp != NULL)
	{
		std::cout << temp->value << "->";
		temp=temp->next;
	}
	std::cout << "NULL\n";
}

void printLLreverse(LLNode * root)
{
	auto temp = root;
	while(temp->next != NULL)
	{
		temp=temp->next;
	}
	while(temp!=NULL)
	{
		std::cout << temp->value << "->";
		temp=temp->prev;
	}
	std::cout << "NULL\n";
}

void createLLUtil(TreeNode * treeRoot, LLNode **llRoot)
{
	if(treeRoot==NULL)
	{
		return;
	}
	createLLUtil(treeRoot->left, llRoot);
	if(*llRoot==NULL)
	{
		*llRoot = new LLNode(treeRoot->value);
	}
	else
	{
		auto temp = *llRoot;
		while(temp->next!= NULL)
		{
			temp=temp->next;
		}
		temp->next = new LLNode(treeRoot->value, temp);
		temp=temp->next;

	}
	createLLUtil(treeRoot->right, llRoot);

}

void createLL(TreeNode * treeRoot)
{
	LLNode* root=NULL;
	createLLUtil(treeRoot, &root);
	printLL(root);
	printLLreverse(root);
	
}

int main()
{
	TreeNode * root = new TreeNode(10);
	root->left = new TreeNode(54);
	root->left->left = new TreeNode(5);
	root->left->right = new TreeNode(4);
	root->right = new TreeNode(9);
	root->right->right = new TreeNode(10);
	root->right->right->right = new TreeNode(18);
	createLL(root);
	return 0;
}