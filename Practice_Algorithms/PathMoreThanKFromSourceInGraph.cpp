/*
Find if there is a path of more than k length from a source
*/

#include <iostream>
#include <vector>

using namespace std;

class Graph
{
public:
	int m_v; // Number of vertices
	std::vector<std::vector<int>> m_adjacencyLists; // adjacency list

	Graph(int v):
	m_v(v)
	{
		m_adjacencyLists.resize(m_v);
	}

	void addEdge(int vertex, int edgeEnd)
	{
		if(vertex > m_v || edgeEnd > m_v)
		{
			std::cout << "Vertex not present\n";
			return;
		}
		m_adjacencyLists.at(vertex). push_back(edgeEnd);
		m_adjacencyLists.at(edgeEnd). push_back(vertex);
	}

	bool findPath(int k, int src, vector<bool> & visited, int index, vector<int> & path)
	{
		if(k==0)
		{
			for(int i =0; i<index; i++)
			{
				cout << path[i] << " ";
			}
			cout <<"\n";
			return true;
		}
		for(auto & each : m_adjacencyLists[src])
		{
			if(!visited[each])
			{
				visited[each] = true;
				path[index] = each;
				index++;
				if(findPath(k-1, each, visited, index, path))
				{
					return true;
				}
				index--;
				visited[each]=false;
			}
		}
		return false;
	}

	bool findPath(int k, int src)
	{
		vector<bool> visited(m_v, false);
		visited[src] = true;
		vector<int> path(m_v, 0);
		path[0] = src;
		int index =1;
		return findPath(k, src, visited, index, path);


	}

	void printAdjacencyList()
	{
		for(int i =0; i< m_v; i++)
		{
			std::cout << i << " : ";
			for(auto const t : m_adjacencyLists.at(i))
			{
				std::cout << t << "->";
			}
			std::cout << "\n";
		}
		std::cout << "\n";

	}
};


int main()
{
	Graph g(7);
	g.addEdge(0,1);
	g.addEdge(0,2);
	g.addEdge(0,3);
	g.addEdge(1,2);
	g.addEdge(2,4);
	g.addEdge(3,5);
	g.addEdge(3,6);
	g.addEdge(2,6);
	g.addEdge(1,5);
	g.printAdjacencyList();
	std::cout << endl;
	std::cout << g.findPath(6, 0) << "\n";
}

