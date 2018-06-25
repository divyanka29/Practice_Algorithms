#include <iostream>
#include "Rover.h"

bool checkValidityOfInputs(Rover::Coordinate const & start, 
							Rover::Coordinate const & end,
							int const width, int const height,
							std::string const & gridStr)
{
	if(width <= 0 || height <= 0)
	{
		return false;
	}
	if(start.X < 0 || start.X >= width || start.Y < 0 || start.Y >= height)
	{
		return false;
	}
	if(end.X < 0 || end.X >= width || end.Y < 0 || end.Y >= height)
	{
		return false;
	}
	return true;
}


int main()
{
	Rover::Coordinate start, end; 
	int width, height;
	std::string gridStr;
	std::cout << "Please enter the start X coordinate : ";
	std::cin >> start.X;
	std::cout << "Please enter the start Y coordinate : ";
	std::cin >> start.Y;
	std::cout << "Please enter the end X coordinate : ";
	std::cin >> end.X;
	std::cout << "Please enter the end Y coordinate : ";
	std::cin >> end.Y;
	std::cout << "Please enter the width : ";
	std::cin >> width;
	std::cout << "Please enter the height : ";
	std::cin >> height;
	std::cout << "Please enter the grid string : ";
	std::cin >> gridStr;

	if(!checkValidityOfInputs(start, end, width, height, gridStr))
	{
		std::cout << "ERROR : Invalid Inputs\n";
		return 0;
	}
	try
	{
		Rover::RoverMapper mapper(width, height, gridStr);
		auto result = mapper.getPath(start, end);
	}
	catch(std::exception const & e)
	{
		std::cout << e.what();
		return 0;
	}
	return 0;
}