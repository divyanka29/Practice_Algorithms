#include <iostream>
#include <vector>


namespace Print
{

template<typename dataType>
void printVector(std::vector<dataType> const & vec, std::string name = "vector")
{
	std::cout << "Printing : " << name <<std::endl;
	for(auto const & t : vec)
	{
		std::cout << std::to_string(t) << " ";
	}
	std::cout << std::endl;
}

}//namespace Print