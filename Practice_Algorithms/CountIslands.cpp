/*Given a boolean 2D matrix, find the number of islands. A group of connected 1s forms an island. For example, the below matrix contains 5 islands

Input : mat[][] = {{1, 1, 0, 0, 0},
                   {0, 1, 0, 0, 1},
                   {1, 0, 0, 1, 1},
                   {0, 0, 0, 0, 0},
                   {1, 0, 1, 0, 1} 
Output : 5*/

#include <iostream>
#include <vector>

bool isValid(std::vector<std::vector<int>> & graph, int r, int c, std::vector<std::vector<bool>> & visited)
{
	if(r>= graph.size())
	{
		return false;
	}
	if(c>= graph[0].size())
	{
		return false;
	}
	if(visited[r][c])
	{
		return false;
	}
	if(graph[r][c]==0)
	{
		return false;
	}
	return true;
}

std::vector<std::pair<int, int>> neighbors{{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

void DFS(std::vector<std::vector<int>> & graph, int r, int c, std::vector<std::vector<bool>> & visited)
{
	visited[r][c] = true;
	for(auto const t : neighbors)
	{
		if(isValid(graph, r+t.first, c+t.second, visited))
		{
			DFS(graph, r+t.first, c+t.second, visited);
		}
	}
}

int countIslands(std::vector<std::vector<int>> & graph)
{
	if(graph.size()==0)
	{
		return 0;
	}
	std::vector<std::vector<bool>> visited(graph.size());
	auto s = graph.at(0).size();
	for(int i =0; i<graph.size(); i++)
	{
		if(graph[i].size() != s)
		{
			std::cout << "Not a valid input\n";
			return 0;
		}
		visited.at(i).resize(s);
	}
	int count = 0;
	for(int r = 0; r < graph.size(); r++)
	{
		for(int c = 0; c < graph[r].size(); c++)
		{
			if(isValid(graph, r, c, visited))
			{
				DFS(graph, r, c, visited);
				count++;
			}
		}
	}
	return count;
}

int main()
{
	std::vector<std::vector<int>> arr{{1, 1, 0, 0, 0},
				                    {0, 1, 0, 0, 1},
				                   	{1, 0, 0, 1, 1},
				                   	{0, 0, 0, 0, 0},
				                   	{1, 0, 1, 0, 1}};
	std::cout << countIslands(arr) << "\n";
	return 0;
}