/*Given a vector of words(input) and given alphabetical sorting order(format), sort the vector of words alphabetically
as per the sorting order
Example
input : {"tacos", "basketball", "baseball", "play", "anticipate", "apple", "zebra", "query"};
format : "qwertyuiopasdfghjklzxcvbnm"
output : {query tacos play apple anticipate zebra baseball basketball}
 
same input
format : abcdefghijklmnopqrstuvwxyz
output : {anticipate apple baseball basketball play query tacos zebra}*/
 
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
 
std::vector<std::string> sortWords(std::vector<std::string> & input, std::string & format)
{
    int i = 0;
    std::unordered_map<char, int> charSort;
    for(auto t : format)
    {
        charSort.insert({t, i});
        i++;
    }

    auto compare = [&](std::string & left, std::string & right){
        int i =0;
        int l = left.size();
        int r = right.size();
        while(i < l && i < r)
        {
            if(charSort[left[i]] < charSort[right[i]])
            {
                return false;
            }
            else if(charSort[left[i]] > charSort[right[i]])
            {
                return true;
            }
            i++;
        }
        return true;
    };

    std::priority_queue<std::string, std::vector<std::string>, decltype(compare)> minWord(compare);
    for(auto const word : input)
    {
        minWord.push(word);
    }
    std::vector<std::string> result;
    while(!minWord.empty())
    {
        result.push_back(minWord.top());
        minWord.pop();
    }
    return result;
}
 
int main()
{
    std::string format = "qwertyuiopasdfghjklzxcvbnm";
    std::vector<std::string> input{"tacos", "basketball", "baseball", "play", "anticipate", "apple", "zebra", "query"};
    auto r = sortWords(input, format);
    for(auto const t : r)
    {
        std::cout << t << " ";
    }
    std::cout << std::endl;
    return 0;
}