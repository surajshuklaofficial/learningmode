#include <iostream>
#include <unordered_map>
#include <vector>
#include <list>
#include <queue>
#include "../index.h"
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;
// Why INFINITY is not working but INT_MAX is working

// DAG
class Graph
{
    unordered_map<int, list<pair<int, int>>> adjList;
    int noOfVertex;
    // vector<int> visited;

public:
    Graph(int noOfVertex)
    {
        this->noOfVertex = noOfVertex;
    }

    void addEdge(int u, int v, int weight)
    {
        pair<int, int> temp(v, weight);
        adjList[u].push_back(temp);
    }

    void printAdjList()
    {
        for (int i = 0; i < noOfVertex; i++)
        {
            cout << i << " --> ";
            for (auto neighbour : adjList[i]) // neigbour == pairs
            {
                cout << "( " << neighbour.first << ", " << neighbour.second << " )";
            }
            cout << endl;
        }
    }

    vector<int> topologicalSort()
    {
        vector<int> indegree(noOfVertex, 0);
        queue<int> tempQ;
        vector<int> ans;

        // intialising indegree vector with indegree of all nodes
        for (int i = 0; i < noOfVertex; i++)
        {
            for (auto j : adjList[i])
            {
                indegree[j.first]++;
            }
        }

        // adding node with indegree 0 to queue
        for (int i = 0; i < noOfVertex; i++)
        {
            if (indegree[i] == 0)
                tempQ.push(i);
        }

        // bfs
        while (!tempQ.empty())
        {
            int front = tempQ.front();
            tempQ.pop();

            ans.push_back(front);

            for (auto neighbour : adjList[front])
            {
                int index = neighbour.first;
                indegree[index]--;
                if (indegree[index] == 0)
                {
                    tempQ.push(index);
                }
            }
        }

        return ans;
    }

    void shortestPath(int startingNode)
    {
        vector<int> ans(noOfVertex, INT_MAX); // Change INFINITY to INT_MAX
        vector<int> ts = topologicalSort();

        ans[startingNode] = 0;

        for (int i : ts)
        {
            if (ans[i] != INT_MAX)
            {
                for (auto j : adjList[i])
                {
                    int index = j.first;              // Corrected variable name
                    int weight = j.second;            // Corrected variable name
                    if (ans[i] + weight < ans[index]) // Changed ans[j.first] to ans[index]
                        ans[index] = ans[i] + weight; // Changed ans[j.first] to ans[index]
                }
            }
        }

        printVec(ans);
    }
};

int main()
{

    Graph g(6);

    g.addEdge(0, 1, 5);
    g.addEdge(0, 3, 2);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 6);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);

    g.printAdjList();

    g.shortestPath(1);

    return 0;
}