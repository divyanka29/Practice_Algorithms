#include <iostream>
#include <fstream>
#include <vector>
#include "Print.h"

void swap(long *a, long *b)
{
	auto temp = *a;
	*a=*b;
	*b=temp;
}

int partitionUsingFirst(std::vector<long> & input, long l, long r, long long & count)
{
	count += (r-l-1);
	long pivot = input.at(l);
	std::cout <<"Pivot : " << pivot << std::endl;
	long lookedAt =l+1;
	long split = l+1;
	while(lookedAt < r)
	{
		if(input.at(lookedAt)<pivot)
		{
			swap(&input.at(split), &input.at(lookedAt));
			split++;
		}
		lookedAt++;
		//count++;
		
	}
	swap(&input.at(l), &input.at(split-1));
	Print::printVector(input);
	return split-1;
}

int partitionUsingLast(std::vector<long> & input, long l, long r, long long & count)
{
	count += (r-l-1);
	swap(&input.at(l), &input.at(r-1));
	long pivot = input.at(l);
	//std::cout <<"Pivot : " << pivot << std::endl;
	long lookedAt =l+1;
	long split = l+1;
	while(lookedAt < r)
	{
		if(input.at(lookedAt)<pivot)
		{
			swap(&input.at(split), &input.at(lookedAt));
			split++;
		}
		lookedAt++;
		//count++;
		
	}
	swap(&input.at(l), &input.at(split-1));
	//Print::printVector(input);
	return split-1;
}

long medianIndex(std::vector<long> & input, long l, long r)
{
	
	long m = (l+r-1)/2;
	long first = input.at(l);
	long last = input.at(r-1);
	if(l+1==r || l==r || l+2==r) return l;

	long middle = input.at(m);	

	if((first < last && first > middle) || (first > last && first < middle))
		return l;
	else if((middle < last && middle > first) || (middle > last && middle < first))
		return m;
	else
		return r-1;
}

int partitionUsingMedian(std::vector<long> & input, long l, long r, long long & count)
{
	count += (r-l-1);
	auto med = medianIndex(input, l,r);
	std::cout << "Median : " << input.at(med) << std::endl;
	swap(&input.at(l), &input.at(med));
	long pivot = input.at(l);
	std::cout <<"Pivot : " << pivot << std::endl;
	long lookedAt =l+1;
	long split = l+1;
	while(lookedAt < r)
	{
		if(input.at(lookedAt)<pivot)
		{
			swap(&input.at(split), &input.at(lookedAt));
			split++;
		}
		lookedAt++;
		//count++;
		
	}
	swap(&input.at(l), &input.at(split-1));
	//Print::printVector(input);
	return split-1;
}

void quickSort(std::vector<long> & input, long l, long r, long long & count)
{
	if(l<r)
	{
		int  p = partitionUsingMedian(input, l, r, count);
		
		quickSort(input, l, p, count);
		
		quickSort(input, p+1, r, count);
	}
	
}

int main()
{
	/*
	long long count =0;
	std::vector<long> input{3,8,2,5,1,4,7,6};
	Print::printVector(input);
	quickSort(input, 0, input.size(), count);
	Print::printVector(input);
	std::cout << "Count : " << count << std::endl;
	*/

	long a;
	long long count =0; //Count of number of comaprisons
	std::ifstream infile("QuickSort.txt");
	std::vector<long> input;
	while (infile >> a)
	{
	    input.push_back(a);
	}
	quickSort(input, 0, input.size(), count);
	std::cout << "Count : " << count << std::endl;
}