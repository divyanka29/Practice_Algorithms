/*
Implement a function that outputs the Look and Say sequence

1 
11
21
1211
111221
312211
13112221
1113213211
31131211131221
13211311123113112211
*/

#include <iostream>
#include <cstdint>

using namespace std;

void printLookAndSay(int N) //N is number of lines to print
{
	if(N<1)
	{
		cout <<"Invalid Input\n";
		return;
	}
	uint64_t prevValue = 1;
	cout << prevValue << endl;

	for(int i =1; i<N; i++)
	{
		uint64_t nextValue = 0;
		uint64_t place = 1;

		while(prevValue != 0)
		{
			int DigitToCount = prevValue%10;
			int count = 1;
			prevValue = prevValue / 10;
			nextValue = nextValue + DigitToCount*place;
			place = place*10;
			
			while(prevValue != 0)
			{
				if(prevValue%10==DigitToCount)
				{
					count++;
					prevValue = prevValue/10;
				}
				else
				{
					break;
				}
			}
			nextValue = nextValue + count*place;
			place=place*10;
		}
		cout << nextValue << endl;
		prevValue = nextValue;
	}
	


}

int main()
{
	printLookAndSay(10);
	return 0;
}