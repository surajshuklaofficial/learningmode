#include <iostream>
#include <unordered_map>
#include <set>
#include <queue>
#include <stack>
using namespace std;

template <class T>
class Graph {
    public:
        unordered_map<int, set<int>> adjList;

        void createGraph() {

            int edges;
            cout << "Enter number of Edges: ";
            cin >> edges;

            for (int i = 0; i < edges; i++) {
                int u, v;
                cin >> u >> v;
                adjList[u].insert(v);
            }
        }

        void print() {

            cout << "printing graph..." << endl;
            for (auto i: adjList) {
                cout << i.first << " -> ";

                for (auto j: i.second) {
                    cout << j << " ";
                }
                cout << endl;
            }
        }

        // Breadth First Search
        void bfs(int startingNode) {
            cout << "printing Breadth First Search..." << endl;
            queue<int> temp;
            unordered_map<int, bool> visited;

            temp.push(startingNode);
            visited[startingNode] = 1;
            
            while (!temp.empty()) {
                cout << temp.front() << " ";

                for (auto i: adjList[temp.front()]) {
                    
                    if (visited[i] !=  1) {
                        temp.push(i);
                        visited[i] = 1;
                    }
                }

                temp.pop();
            }
            cout << endl;
        }

        // Depth First Search
        void dfs(int startingNode) {
            cout << "printing Depth First Traversal..." << endl;

            stack<int> temp;
            unordered_map<int, bool> visited;

            temp.push(startingNode);
            visited[startingNode] = 1;

            while (!temp.empty()) {
                int currentVertex = temp.top();

                cout << currentVertex << " ";
                temp.pop();

                for (auto i: adjList[currentVertex]) {
                    if (visited[i] !=  1) {
                        temp.push(i);
                        visited[i] = 1;
                    }
                }
            }

            cout << endl;
        }
};

// class Graph {
//     public:
//         unordered_map<int, list<int>> adjList;
//         void addEdge(int u, int v, bool directed) {
//             // directed = 0 -> undirected
//             // directed = 1 -> directed
//             // create an edge from u to v
//             adjList[u].push_back(v);
//             // creating edge from v to u, if directed
//             if (directed == 1) adjList[v].push_back(u);
//         }
//         void print() {
//             for (auto i: adjList) {
//                 cout << i.first << "->";
//                 for (auto j: i.second) {
//                     cout << j << ", ";
//                 }
//                 cout << endl;
//             }
//         }
// };
int main() {
    Graph<int> g;
    g.createGraph();

    g.print();

    g.bfs(1);
    g.dfs(1);

    return 0;
}