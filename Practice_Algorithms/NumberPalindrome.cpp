/*
Check if a number is a palindrome in O(1) space
*/

#include <iostream>
#include <math.h>   

int getLength(long n)
{
	int count = 0;
	while(n%10)
	{
		n=n/10;
		count++;
	}
	return count;
}

bool isPalindrome(long n)
{

	if(n<0)
	{
		return false;
	}
	auto length = getLength(n);
	if(length==1)
	{
		return true;
	}
	int r=10, l= pow(10,length-1);
	while(n && r <=l)
	{
		if(n%r!=n/l)
		{
			return false;
		}
		n=(n%l)/r;
		l=l/100;
	}
	return true;
}

int main()
{
	if(isPalindrome(12321))
	{
		std::cout <<"Is Palindrome\n";
	}
	else
	{
		std::cout <<"Not Palindrome\n";
	}
	return 0;
}