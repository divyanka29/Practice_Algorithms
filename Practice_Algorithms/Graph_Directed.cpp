#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>


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

	void addEdge(int vertex, std::vector<int> nodes)
	{
		if(vertex > m_v)
		{
			std::cout << "Vertex not present\n";
			return;
		}
		auto & list = m_adjacencyLists.at(vertex);
		for(auto const &t : nodes)
		{
			list.push_back(t);
		}
		
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

	void topologicalSorting()
	{
		std::stack<int> t_stack;
		std::vector<bool> visited(m_v, false);
		for(int i =0; i < m_v; i++)
		{
			if(!visited.at(i))
			{
				topologicalSortingHelper(i, visited, t_stack);
			}
		}
		
		std::cout << "Topoplogical Sorting : ";
		while(!t_stack.empty())
		{
			std::cout << t_stack.top() << " ";
			t_stack.pop();
		}
		std::cout << "\n";
	}
private:
	void topologicalSortingHelper(int root, std::vector<bool> & visited, std::stack<int> & t_stack)
	{
		if(visited.at(root))
		{
			return;
		}
		visited.at(root) = true;
		for(auto const & n : m_adjacencyLists.at(root))
		{
			topologicalSortingHelper(n, visited, t_stack);
		}
		t_stack.push(root);
		
	}
};

int main()
{
	Graph g(6);
	g.addEdge(0,{});
	g.addEdge(1,{});
	g.addEdge(2,{3});
	g.addEdge(3,{1});
	g.addEdge(4,{0,1});
	g.addEdge(5,{2,0});
	g.printAdjacencyList();
	g.topologicalSorting();
	return 0;
}

