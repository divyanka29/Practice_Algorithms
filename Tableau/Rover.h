#include <string>
#include <vector>
#include <utility>

namespace Rover
{

struct Coordinate
{
	int X;
	int Y;
};

using Grid = std::vector<std::vector<int>>;

class RoverMapper
{
public:
	RoverMapper(int width, int height, std::string & gridStr);
	//bool getPath(Coordinate start, Coordinate end);
private:

	void createGrid(std::string & gridStr);

	int m_width;
	int m_height;
	Grid m_grid;

};

}//namespace