/*Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example 1:
[[1,3,1],
 [1,5,1],
 [4,2,1]]
Given the above grid map, return 7. Because the path 1→3→1→1→1 minimizes the sum.*/
#include <iostream>
#include <vector>
#include "Print.h"

using namespace std;

void print(vector<vector<int>>& grid)
{
    for(auto const vec : grid)
    {
        for(auto const & t : vec)
        {
            std::cout << std::to_string(t) << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int minPathSum(vector<vector<int>>& grid) {
    if(grid.size()==0)
    {
        return -1;
    }
    if(grid.at(0).size()==0)
    {
        return -1;
    }
    vector<vector<int>> visited;
    visited.resize(grid.size());
    for(int i =0; i<grid.size(); i++)
    {
        visited[i].resize(grid[i].size());
        for(int j = 0; j < grid.at(0).size(); j++)
        {
            visited[i][j] = -1;
        }
    }
    print(grid);
    int row =0;
    int col = 0;
    visited[0][0] = grid[0][0];
    
    for(row=0; row<grid.size()-1; row++)
    {
        for(col=0; col<grid.at(row).size()-1; col++)
        {
            int curr = visited[row][col];
            int inputRight = grid[row][col+1];
            cout<<"Current : " <<curr<<endl;
            if(visited[row][col+1]==-1)
            {
                visited[row][col+1] = curr + inputRight;
            }
            else
            {
                if(visited[row][col+1] > curr + inputRight)
                {
                    visited[row][col+1] = curr + inputRight;
                }
            }
            cout << "After changing right : "<<endl;
            print(visited);
            int inputBottom = grid[row+1][col];
            if(visited[row+1][col]==-1)
            {
                visited[row+1][col] = curr + inputBottom;
            }
            else
            {
                if(visited[row+1][col] > curr + inputBottom)
                {
                    visited[row+1][col] = curr + inputBottom;
                }
            }
            cout << "After changing bottom : "<<endl;
            print(visited);

        }
    }
    int lastColumn = grid.at(0).size()-1;
    cout<<"Handle last column"<<endl;
    for(row =0; row<grid.size()-1; row++)
    {
        int curr = visited[row][lastColumn];
        cout<<"Current : " <<curr<<endl;
        int inputBottom = grid[row+1][lastColumn];
        if(visited[row+1][lastColumn]==-1)
        {
            visited[row+1][lastColumn] = curr + inputBottom;
        }
        else
        {
            if(visited[row+1][lastColumn] > curr + inputBottom)
            {
                visited[row+1][lastColumn] = curr + inputBottom;
            }
        }
        cout << "After changing bottom : "<<endl;
        print(visited);
    }

    int lastRow = grid.size()-1;
    cout<<"Handle last row"<<endl;
    for(col = 0; col < grid.at(lastRow).size()-1; col++)
    {
        int curr = visited[lastRow][col];
        int inputRight = grid[lastRow][col+1];
        cout<<"Current : " <<curr<<endl;
        if(visited[lastRow][col+1]==-1)
        {
            visited[lastRow][col+1] = curr + inputRight;
        }
        else
        {
            if(visited[lastRow][col+1] > curr + inputRight)
            {
                visited[lastRow][col+1] = curr + inputRight;
            }
        }
        cout << "After changing right : "<<endl;
        print(visited);
    }
    print(visited);
    return visited[visited.size()-1][visited.at(0).size()-1];
}

int main()
{
    vector<vector<int>> input{{1,3,1},{1,5,1},{4,2,1}};
    cout << minPathSum(input)<<endl;

}