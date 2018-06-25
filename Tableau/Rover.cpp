#include <iostream>
#include "Rover.h"


namespace Rover
{

RoverMapper::RoverMapper(int width, int height, std::string & gridStr):
	m_width(width),
	m_height(height)
{
	if(gridStr.size() != width*height)
	{
		throw std::runtime_error("Bad input string for grid\n");
	}
	createGrid(gridStr);
	std::cout << "Created Rover Mapper!!\n";
}

bool RoverMapper::getPath(Coordinate start, Coordinate end)
{
	return true;
}

void RoverMapper::createGrid(std::string & gridStr)
{
	m_grid.resize(m_height);
	for(auto & each : m_grid)
	{
		each.resize(m_width);
	}
	int h = 0;
	for(int i = 0; i<gridStr.size(); i++)
	{
		int w = 0;
		while(w < m_width)
		{
			m_grid[w][h] = (int)(gridStr[i]);
			w++;
		}
		h++;
	}
}

}//namespace