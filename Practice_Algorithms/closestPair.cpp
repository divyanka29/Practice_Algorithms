//Find the closest pair from two sorted arrays
//Given two sorted arrays and a number x, find the pair whose sum is closest to x and the pair has an element from each array.

#include <iostream>
#include <vector>


void closestPair(std::vector<int> & a1, std::vector<int> & a2, int x)
{
	//We merge the 2 vectors and keep track of which value is part of which array using whichArr vector
	//if part of a1 then false and if part of a2 then true
	std::vector<bool> whichArr(a1.size()+a2.size(), false);
	std::vector<int> merged;
	int i = 0, j=0, k=0;
	while(i<a1.size() || j<a2.size())
	{
		if(a1[i] < a2[j])
		{
			merged.push_back(a[i]);
			i++;
			k++;
		}
		else if(a2[j]<a1[i])
		{
			merged.push_back(a2[j]);
			whichArr.at(k) = false;
			k++;
			j++;
		}
		else
		{
			merged.push_back(a[i]);
			i++;
			k++;
			merged.push_back(a2[j]);
			whichArr.at(k) = false;
			k++;
			j++;

		}
	}
}

int main()
{
	std::vector<int> a1 {1, 4, 5, 7};
	std::vector<int> a2 {10, 20, 30, 40};
	return 0;
}