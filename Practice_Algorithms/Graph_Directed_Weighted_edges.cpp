#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <limits>

struct Node
{
	int m_vertex;
	int m_weight;
};

class Graph
{
	int m_vertices;
	std::vector<std::vector<Node>> m_adjacencyList;

public:
	Graph(int vertices)
	{
		m_vertices = vertices;
		m_adjacencyList.resize(m_vertices);
	}

	void addEdge(int u, int v, int w)
	{
		auto & list = m_adjacencyList.at(u);
		list.push_back(Node{v, w});
	}

	void print()
	{
		std::cout << "Graph Adjacency List : \n";
		for(int i=0; i<m_adjacencyList.size(); i++)
		{
			std::cout << i << " : ";
			for(auto const & t : m_adjacencyList.at(i))
			{
				std::cout << "(" << t.m_vertex << "," << t.m_weight << ")->";
			}
			std::cout << "\n";
		}
	}

	std::vector<int> topologicalSort()
	{
		std::stack<int> t_stack;
		std::vector<bool> visited(m_vertices, false);
		for(int i =0; i<m_vertices; i++)
		{
			if(!visited.at(i))
			{
				topologicalSortHelper(i, t_stack, visited);
			}
		}
		std::vector<int> result;
		std::cout << "Topoplogical Sorting : ";
		while(!t_stack.empty())
		{
			auto top = t_stack.top();
			std::cout << top << " ";
			result.push_back(top);
			t_stack.pop();
		}
		std::cout << "\n";
		return result;
	}

	void longestDistances(int source)
	{
		auto vec =  topologicalSort();
		std::vector<int> distances;
		for(int i =0 ; i<m_vertices; i++)
		{
			distances.push_back(-999);
		}
		distances.at(source) = 0;
		distances[source]=0;
		auto it = std::find(vec.begin(), vec.end(), source);
		while(it != vec.end())
		{
			for(auto const & t : m_adjacencyList.at(*it))
			{
				if(distances.at(t.m_vertex) < distances.at(*it) + t.m_weight)
				{
					distances.at(t.m_vertex) = distances.at(*it) + t.m_weight;
				}
			}
			it++;
		}
		std::cout<< "for source : " <<source <<"\n";
		for(int i =0; i < distances.size(); i++)
		{
			if(distances.at(i) == -999)
			{
				std::cout << i << " : INF\n";
			}
			else
			{
				std::cout << i << " : " << distances.at(i) << "\n";
			}
		}
		std::cout << "\n";

	}

private:
	void topologicalSortHelper(int root, std::stack<int> & t_stack, std::vector<bool> & visited)
	{
		if(visited.at(root))
		{
			return;
		}
		visited.at(root) = true;
		for(auto const & t : m_adjacencyList.at(root))
		{
			topologicalSortHelper(t.m_vertex, t_stack, visited);
		}
		t_stack.push(root);
	}

};

int main()
{
	Graph g(6);
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 3, 6);
    g.addEdge(1, 2, 2);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(2, 3, 7);
    g.addEdge(3, 5, 1);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);
    g.print();
    auto vec = g.topologicalSort();
    g.longestDistances(2);
	return 0;
}