//Selection Sort

#include <iostream>
#include <vector>
#include "Print.h"

void swap(std::vector<int>::iterator & first, std::vector<int>::iterator & second)
{
	int temp = *first;
	*first = *second;
	*second = temp; 
}

std::vector<int>::iterator findSmallest(std::vector<int>::iterator start, std::vector<int>::iterator end, std::vector<int> & vec)
{
	auto smallest = start;
	for(auto it = start+1; it != end; it++)
	{
		if(*it < *smallest)
		{
			smallest = it;
		}
	}
	return smallest;
}


void selectionSort(std::vector<int> & vec)
{
	if(vec.size()==0)
	{
		return;
	}
	std::vector<int>::iterator currentPosition = vec.begin();
	while(currentPosition != vec.end()-1)
	{
		auto smallest = findSmallest(currentPosition+1, vec.end(), vec);
		if(*smallest < *currentPosition)
		{
			swap(smallest, currentPosition);
		}
		currentPosition++;
	}
}

int main()
{
	std::vector<int> vec = {};
	Print::printVector(vec, "Original Vector");
	selectionSort(vec);
	Print::printVector(vec, "Sorted Vector");
	return 0;
}