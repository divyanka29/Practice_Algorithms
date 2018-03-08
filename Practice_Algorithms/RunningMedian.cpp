/*The median of a dataset of integers is the midpoint value of the dataset for which an equal number of integers are less than and greater than the value. To find the median, you must first sort your dataset of integers in non-decreasing order, then:

If your dataset contains an odd number of elements, the median is the middle element of the sorted sample. In the sorted dataset ,  is the median.
If your dataset contains an even number of elements, the median is the average of the two middle elements of the sorted sample. In the sorted dataset ,  is the median.
Given an input stream of  integers, you must perform the following task for each  integer:

Add the  integer to a running list of integers.
Find the median of the updated list (i.e., for the first element through the  element).
Print the list's updated median on a new line. The printed value must be a double-precision number scaled to decimal place (i.e.,  format).
Input Format

The first line contains a single integer, , denoting the number of integers in the data stream. 
Each line  of the  subsequent lines contains an integer, , to be added to your list.

Constraints

Output Format

After each new integer is added to the list, print the list's updated median on a new line as a single double-precision number scaled to  decimal place (i.e.,  format).

Sample Input

6
12
4
5
3
8
7
Sample Output

12.0
8.0
5.0
4.5
5.0
6.0*/

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <iomanip>

using namespace std;

template<typename MaxQ, typename MinQ>
void median(MaxQ & maxq, MinQ & minq, int size, int value)
{
	//cout << "Size : " <<size <<endl;
    if(size == 1)
    {
    	maxq.push(value);
    	double val = value/1.0;
    	cout << fixed << showpoint; cout << setprecision(1) <<val<<endl;
    	return;
    }
    if(size == 2)
    {
    	if(value < maxq.top())
    	{
    		minq.push(maxq.top());
    		maxq.pop();
    		maxq.push(value);
    	}
    	else
    	{
    		minq.push(value);
    	}
    	//cout << "Max : " <<maxq.top() << " Min : " <<minq.top() << endl; 
    	double val = (maxq.top()+minq.top())/2.0;
    	cout << fixed << showpoint; cout << setprecision(1) <<val<<endl;
    	return;
    }
    if(size%2 == 0)
    {
    	//cout << "Size is even\n";
    	if(maxq.size() > minq.size())
    	{
    		//cout << "Maxq size greater than minq size\n";
    		if(value < maxq.top())
    		{
    			//cout << "Value smaller than maxq top\n";
	    		minq.push(maxq.top());
	    		maxq.pop();
	    		maxq.push(value);
    		}
    	
	    	else
	    	{
	    		//cout << "Value greater than maxq top\n";
    			minq.push(value);
	    	}
	    	//cout << "Max : " <<maxq.top() << " Min : " <<minq.top() << endl; 
	    	double val = (maxq.top()+minq.top())/2.0;
	    	cout << fixed << showpoint; cout << setprecision(1) <<val<<endl;
	    	return;
	    }
	    else
	    {
	    	//cout << "Minq size greater than maxq size\n";
	    	if(value > minq.top())
	    	{
	    		//cout << "Value greater than maxq top\n";
	    		maxq.push(minq.top());
	    		minq.pop();
	    		minq.push(value);
	    	}
	    	else
	    	{
	    		//cout << "Value smaller than maxq top\n";
	    		maxq.push(value);
	    	}
	    	//cout << "Max : " <<maxq.top() << " Min : " <<minq.top() << endl; 
	    	double val = (maxq.top()+minq.top())/2.0;
    		cout << fixed << showpoint; cout << setprecision(1) <<val<<endl;
    		return;
	    }
    }
    else
    {
    	//cout << "Size is odd\n";
    	if(value<maxq.top())
    	{
    		//cout << "Value smaller than maxq top\n";
    		maxq.push(value);
    		//cout << "Max : " <<maxq.top() << " Min : " <<minq.top() << endl; 
    		double val = maxq.top()/1.0;
	    	cout << fixed << showpoint; cout << setprecision(1) <<val<<endl;
	    	return;
    	}
    	else
    	{
    		//cout << "Value greater than maxq top\n";
    		minq.push(value);
    		//cout << "Max : " <<maxq.top() << " Min : " <<minq.top() << endl; 
    		double val = minq.top()/1.0;
	    	cout << fixed << showpoint; cout << setprecision(1) <<val<<endl;
	    	return;
    	}
    }
}


int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    priority_queue<int> maxq;
    priority_queue<int, vector<int>, greater<int>> minq;
    for(int a_i = 0;a_i < n;a_i++){
       cin >> a[a_i];
       median(maxq, minq, a_i+1, a[a_i]);
    }
    return 0;
}