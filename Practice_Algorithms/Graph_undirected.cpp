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

	void BFS(int root)
	{
		std::cout << "BFS for "<< root << " : ";
		std::queue<int> t_queue;
		t_queue.push(root);
		std::unordered_map<int, bool> visited;	
		while(!t_queue.empty())
		{
			auto t = t_queue.front();
			t_queue.pop();
			if(visited.find(t) == visited.end())
			{
				visited.insert({t, true});
				std::cout << t << " ";
				for(auto const n : m_adjacencyLists[t])
				{
					t_queue.push(n);
				}	
			}
		}
		std::cout <<"\n";
	}
	void DFS_recursion(int root)
	{
		std::vector<bool> visited(m_v, false);
		std::cout << "DFS by recursion for " << root << " : ";
		DFS_Helper(root, visited);
		std::cout <<"\n";
	}

	void DFS_stack(int root)
	{
		std::vector<bool> visited(m_v, false);
		std::cout << "DFS by stack for " << root << " : ";
		std::stack<int> t_stack;
		t_stack.push(root);
		while(!t_stack.empty())	
		{
			auto t = t_stack.top();
			t_stack.pop();
			if(visited.at(t))
			{
				continue;
			}
			visited.at(t) = true;
			std::cout << t << " ";
			for(auto const n : m_adjacencyLists.at(t))
			{
				t_stack.push(n);
			}
		}
		std::cout <<"\n";
	}

private:
	void DFS_Helper(int root, std::vector<bool> & visited)
	{
		if(visited.at(root) ==  true)
		{
			return;
		}
		std::cout << root << " ";
		visited.at(root) = true;
		for(auto const t : m_adjacencyLists.at(root))
		{
			DFS_Helper(t, visited);
		}

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
	g.BFS(0);
	g.DFS_recursion(0);
	g.DFS_stack(0);
	return 0;
}

