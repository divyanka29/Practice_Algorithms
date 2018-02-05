//Search an element in a sorted and rotated array
//An element in a sorted array can be found in O(log n) time via binary search. 
//But suppose we rotate an ascending order sorted array at some pivot unknown 
//to you beforehand. So for instance, 1 2 3 4 5 might become 3 4 5 1 2. 
//Devise a way to find an element in the rotated array in O(log n) time.

/*1) Find middle point mid = (l + h)/2
2) If key is present at middle point, return mid.
3) Else If arr[l..mid] is sorted
    a) If key to be searched lies in range from arr[l]
       to arr[mid], recur for arr[l..mid].
    b) Else recur for arr[mid+1..r]
4) Else (arr[mid+1..r] must be sorted)
    a) If key to be searched lies in range from arr[mid+1]
       to arr[r], recur for arr[mid+1..r].
    b) Else recur for arr[l..mid] */

#include <iostream>
#include <vector>

int find(std::vector<int> & arr, int left, int right, int k)
{
	int mid = (left + right) / 2;
	if(arr.at(mid) == k)
	{
		return mid;
	}
	else if(arr.at(left) < arr.at(mid)) //if sorted
	{
		if(k > arr.at(left) && k <arr.at(mid))
		{
			return find(arr, left, mid, k);
		}
		else
		{
			return find(arr, mid+1, right, k);
		}
	}
	else if (arr.at(mid+1) < arr.at(right))
	{
		if(k > arr.at(mid+1) && k < arr.at(right))
		{
			return find(arr, mid+1, right, k);
		}
		else
		{
			return find(arr, left, mid, k);
		}
	}
	return -1;
}








int main(int argc, char const *argv[])
{
	std::vector<int> v = {3,4,5,1,2};
	std::cout << find(v, 0, 4, 2) << std::endl;
	return 0;
}