/*
Given input list of possibly overlapping intervals, not sorted, give output list of intervals that cover the same range but 
without overlapping.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void getDistinctIntervals(vector<pair<int, int>> & intervals)
{
	if(intervals.size()==0)
	{
		return;
	}
	auto compare = [](pair<int, int> a, pair<int, int> b)
	{
		return a.first < b.first;
	};
	std::sort(intervals.begin(), intervals.end(), compare);
	
	int index = 0;
	for(int i =1; i<intervals.size(); i++)
	{
		if(intervals[i].first < intervals[index].second)
		{
			if(intervals[i].second > intervals[index].second)
			{
				intervals[index].second = intervals[i].second;
			}
		}
		else
		{
			index++;
			intervals[index] = intervals[i];
		}
	}
	index++;
	for(int i =0; i<index; i++)
	{
		std::cout << intervals[i].first <<" " <<intervals[i].second << "\n";
	}
}

int main()
{
	vector<pair<int, int>> a{
		{2,5}, {4,9}, {15,20}, {8,10}
	};
	getDistinctIntervals(a);
}