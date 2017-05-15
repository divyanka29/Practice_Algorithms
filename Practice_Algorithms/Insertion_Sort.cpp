//Insertion Sort

#include "Print.h"

#include <iostream>
#include <vector>
#include <iterator>

void insertAndMove(std::vector<int>::iterator & toMovePosition, std::vector<int>::iterator & currentPosition, std::vector<int> & vec)
{
	int value = *currentPosition;
	while(currentPosition != toMovePosition)
	{
		*currentPosition = *(currentPosition - 1);
		currentPosition--;
	}
	*currentPosition = value;
	
}

void insertionSort(std::vector<int> & vec)
{
	
	for(auto currentPosition = vec.begin()+1; currentPosition != vec.end(); currentPosition++)
	{
		auto comparePosition = vec.begin();
		while(comparePosition != currentPosition)
		{
			if(*currentPosition < *comparePosition)
			{
				insertAndMove(comparePosition, currentPosition, vec);
				break;
			}
			comparePosition++;
		}
	}
	
}

int main()
{
	std::vector<int> vec = {5,2,8,13,22,9,1,80,4};
	Print::printVector(vec, "Original Vector");
	insertionSort(vec);
	Print::printVector(vec, "Sorted Vector");

	return 0;
}