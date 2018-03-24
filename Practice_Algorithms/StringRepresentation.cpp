/*
Given a number of size <= 999 billion, return its String representation (for 123, return "One Hundred Twenty Three," not "123").
*/


//999,999,999,999
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<int, string> ones{
	{0, ""},
	{1, "one"},
	{2, "two"},
	{3, "three"},
	{4, "four"},
	{5, "five"},
	{6, "six"},
	{7, "seven"},
	{8, "eight"},
	{9, "nine"}
};

unordered_map<int, string> tens{
	{0, ""},
	{1, ""},
	{2, "twenty"},
	{3, "thirty"},
	{4, "forty"},
	{5, "fifty"},
	{6, "sixty"},
	{7, "seventy"},
	{8, "eighty"},
	{9, "ninety"}
};

unordered_map<int, string> teens{
	{0, "ten"},
	{1, "eleven"},
	{2, "twelve"},
	{3, "thirteen"},
	{4, "fourteen"},
	{5, "fifteen"},
	{6, "sixteen"},
	{7, "seventeen"},
	{8, "eighteen"},
	{9, "nineteen"}
};



string getString(std::vector<int> & digits)
{
	if(digits.size()==0)
	{
		return "";
	}
	if(digits.size() == 1)
	{
		return ones[digits[0]];
	}
	string returnStr = "";
	if(digits[1]==1)
	{
		returnStr = returnStr + teens[digits[0]];
	}
	else
	{
		returnStr = returnStr + ones[digits[0]];
		returnStr = tens[digits[1]] + " " + returnStr;
	}
	if(digits.size()>2)
	{
		if(digits[2] != 0)
		{
			returnStr = " hundred " + returnStr;
			returnStr = ones[digits[2]] + returnStr;

		}
	}
	return returnStr;
}

void stringRepresentation(long long value)
{
	string result;
	std::vector<string> places {"", "thousand" , "million", "billion"};

	std::vector<std::vector<int>> eachThree;

	for(int i =0; i<4; i++)
	{
		if(value)
		{
			vector<int> current;
			for(int j = 0; j<3; j++)
			{
				if(value)
				{
					auto t = value%10;
					value = value/10;
					current.push_back(t);
				}
				else
				{
					break;
				}
			}
			eachThree.push_back(current);
		}
		else
		{
			break;
		}	
	}


	if(eachThree.size() == 0)
	{
		return;
	}
	if(eachThree.size() == 1)
	{
		std::cout << getString(eachThree[0]) << "\n";
		return;
	}
	for(int i = eachThree.size()-1; i>=0; i--)
	{
		cout << getString(eachThree[i]) << " " << places[i] << " ";
	}

	cout << "\n";
}


int main()
{
	stringRepresentation(9513070153);
}