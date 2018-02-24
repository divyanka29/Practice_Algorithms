#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include "Print.h"

using namespace std;

#include <bits/stdc++.h>
#include <queue>

using namespace std;

void countInv(std::vector<long> & input, long l, long m, long r, long long & count)
{
	std::vector<long> left, right;
	for(long i = l; i<=m; i++) 
	{
		left.push_back(input.at(i));
	}
	for(long i = m+1; i<=r; i++) 
	{
		right.push_back(input.at(i));
	}
	long k = l, i =0, j =0;
    int lSize = left.size();
    int rSize = right.size();
	while(true)
	{
        if(i>=lSize || j>=rSize)
        {
            break;
        }
		if(left.at(i) <= right.at(j))
		{
			input.at(k) = left.at(i);
			i++;
		}
		else
		{
			input.at(k)=right.at(j);
			j++;
			count = count + lSize-i;
		}
		k++;
        
        
	}
    while(i != lSize)
	{
		input.at(k) = left.at(i);
        i++;
		k++;
	}
}

void mergeSort(std::vector<long> & input, long l, long r, long long & count)
{
	if(l>=r)
	{
		return;
	}
	long m = (l+r)/2;
	mergeSort(input, l, m, count);
	mergeSort(input, m+1, r, count);
	countInv(input, l, m, r, count);
}

int main() {
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        vector<long> arr(n);
        for(int arr_i = 0; arr_i < n; arr_i++){
           cin >> arr[arr_i];
        }
        long long count = 0;
        mergeSort(arr, 0, arr.size()-1, count);
        cout << count << endl;
    }
    return 0;
}



void countInversionStandard(std::vector<long> & input)
{
	long long count =0;
	for(long i =0; i<input.size(); i++)
	{
		for(long j = i + 1; j < input.size(); j++)
		{
			if (input[i] > input[j])
			{
				count++;
			}
                    
		}
	}
	std::cout << "Count : " <<count <<"\n";
}



int main()
{
	long a;
	std::ifstream infile("IntegerArray.txt");
	std::vector<long> input;
	while (infile >> a)
	{
	    input.push_back(a);
	}
	std::cout << "By standard method : \n";
	countInversionStandard(input);

	long long count = 0;
	mergeSort(input, 0, input.size()-1, count);
	//Print::printVector(input, "Sorted Vector");

	std::cout << "Count : " <<count <<"\n";
	return 0;
}