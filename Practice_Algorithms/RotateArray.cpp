//Write a function rotate(ar[], d, n) that rotates arr[] of size n by d elements.

#include <iostream>
#include <vector>
#include "Print.h"

void rotateArray(std::vector<int> & arr, int size, int d)
{
	if(size == 0 || size == 1 || d == 0) return;
	for(int i = 0; i < d; i++)
	{
		int temp = arr.at(0);
		for(int j=0; j<size-1; j++)
		{
			arr.at(j) = arr.at(j+1);
		}
		arr.at(size-1) = temp;
	}
}



int main()
{
	std::vector<int> a = {1,2,3};
	rotateArray(a, a.size(), 2);
	Print::printVector(a);
	return 0;
}