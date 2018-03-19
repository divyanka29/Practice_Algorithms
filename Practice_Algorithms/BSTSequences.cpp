/*
BST Sequences : A binary search tree was created by traversing 
				through an array from left to right and inserting
				each element. Givena binary search tree with distinct elements,
				print all possible arrays that could have led to this tree

Input:

				2
			   / \
			  1   3

Output {2,1,3}, {2,3,1}
*/


using namespace std;
struct Node
{
	Node(int data) : 
	data(data),
	left(NULL),
	right(NULL)
	{}

	int data;
	Node* left;
	Node* right;
};

vector<vector<int>> shuffleSequences(vector<int> & a, vector<int> & b)
{
	if(a.size()==0)
	{
		return vector<vector<int>>{b};
	}
	if(b.size()==0)
	{
		return vector<vector<int>>{a};
	}
	vector<vector<int>> results;
	results.push_back(a);
	int i =0;
	for(auto const & eachb : b)
	{
		vector<int> temp(a.size() + b.size());
		for(int j =0; j < a.size(); j++)
		{

		}
	}
}


vector<vector<int>> getArrays(Node * root)
{

}

int main()
{
	Node* root = new Node(4);
	root->right = new Node(6);
	root->left = new Node(2);
	root->left->left = new Node(1);
	root->left->right = new Node(3);
	root->right->right = new Node(9);
}