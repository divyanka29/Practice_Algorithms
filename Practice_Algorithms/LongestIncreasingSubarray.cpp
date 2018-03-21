#include <iostream>
#include <vector>

using namespace std;

int longestSubsequence(vector<int> & a)
{
	if(a.size()==0 || a.size()==1)
	{
		return a.size();
	}
	int max = 1;
	int count = 1;
	for(int i =1; i< a.size(); i++)
	{
		if(a[i] >= a[i-1])
		{
			count++;
		}
		else
		{
			if(count > max)
			{
				max = count;
			}
			count = 1;
		}
	}
	return max;
}

int main()
{
	vector<int> a{4, 5, 6, 2, 8, 1, 2, 1, 6};
	cout << longestSubsequence(a) <<endl;
	return 0;
}