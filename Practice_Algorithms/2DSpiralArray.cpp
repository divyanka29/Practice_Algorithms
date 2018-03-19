/*
Find the pattern and complete the function: 
int[][] spiral(int n);
where n is the size of the 2D array.

Sample Result
input = 3
123
894
765

input = 4
01 02 03 04
12 13 14 05
11 16 15 06
10 09 08 07

input = 8
1 2 3 4 5 6 7 8
28 29 30 31 32 33 34 9
27 48 49 50 51 52 35 10
26 47 60 61 62 53 36 11
25 46 59 64 63 54 37 12
24 45 58 57 56 55 38 13
23 44 43 42 41 40 39 14
22 21 20 19 18 17 16 15
*/

#include <iostream>
#include <vector>
#include "Print.h"

using namespace std;

bool validMove(vector<vector<int>> & result, int next_r, int next_c)
{
	if(next_r < 0 || next_c < 0 || next_r >= result.size() || next_c >= result[next_r].size() || result[next_r][next_c] != 0)
	{
		return false;
	}
	return true;
}


vector<vector<int>> spiral(int N)
{
	if(N<0)
	{
		throw("Invalid Arguments");
	}
	vector<vector<int>> result(N);
	for(auto & each : result)
	{
		each.resize(N);
	}

	int count = 1;
	auto right = pair<int, int>(0, 1);
	auto down = pair<int, int>(1, 0);
	auto left = pair<int, int>(0, -1);
	auto up = pair<int, int>(-1, 0);
	vector<pair<int, int>> directions{right, down, left, up};

	int r = 0, c = 0;
	int curr_direction = 0;
	while(count <=N*N)
	{
		result[r][c]=count;
		count++;
		if(validMove(result, r + directions[curr_direction].first, c + directions[curr_direction].second))
		{	
			r = r + directions[curr_direction].first;
			c = c + directions[curr_direction].second;
		}
		else
		{
			curr_direction = (curr_direction+1)%4;
			r = r + directions[curr_direction].first;
			c = c + directions[curr_direction].second;
		}

	}
	return result;
}

int main()
{
	auto result = spiral(3);
	for(auto const & t : result)
	{
		Print::printVector(t);
	}
}