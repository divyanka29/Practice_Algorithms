/*
Given an input array like [1,2,3] and a target like 5, find all combinations of array that sum up to target. [2,3] and [3,2] counts for only 1 combination.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include "Print.h"
using namespace std;

void getSum(vector<int> & values, int sum, int start, vector<int> & data, int &index, int currSum)
{
	
	if(currSum ==sum)
	{
		for(int i =0; i< index; i++)
		{
			cout << data[i] << " ";
		}
		cout << "\n";
		index--;
		return;
	}
	for(int i = start+1; i<values.size(); i++)
	{
		if(currSum + values[i] > sum)
		{
			continue;
		}
		data[index] = values[i];
		index++;
		getSum(values, sum, i, data, index, currSum+values[i]);
	}
	index--;
	
}


void getSum(vector<int> & values, int sum)
{
	for(int i=0; i<values.size(); i++)
	{
		vector<int> data(values.size());
		data[0] = values[i];
		int index = 1;
		getSum(values, sum, i, data, index, values[i]);
	}
}

int main(int argc, char const *argv[])
{
	vector<int> a{4, 9, 1, 5, 2, 7, 8, 3};
	getSum(a, 10);
	return 0;
}