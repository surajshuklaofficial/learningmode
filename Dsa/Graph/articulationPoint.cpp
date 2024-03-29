#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility> 
#include <list>
#include "../index.h"
using namespace std;

void DFS(int node, int parent, vector<int> &disc, vector<int> &low, unordered_map<int, bool> &vis, unordered_map<int, list<int>> &adj, vector<int> &ap, int timer) {
    vis[node] = true;
    disc[node] = low[node] = timer++;
    // disc[node] = timer;
    // low[node] = timer;

    int child = 0;
    for(auto nbr: adj[node]) {
        if (nbr == parent) continue;
        
        if (!vis[nbr]) {
            DFS(nbr, node, disc, low, vis, adj, ap, timer);
            // DFS(nbr, node, disc, low, vis, adj, ap, timer + 1);
            low[node] = min(low[node], low[nbr]);

            // check AP or not
            if (low[nbr] >= disc[node] && parent != -1) {
                ap[node] = true;
            } 
            child++;
        } else {
            low[node] = min(low[node], disc[nbr]);
        }
    }

    if (parent == -1 && child > 1) ap[node] = true;
}

int main() {
    int n = 5;
    int e = 5;
    vector<pair<int, int>> edges;
    edges.push_back(make_pair(0, 3));
    edges.push_back(make_pair(3, 4));
    edges.push_back(make_pair(0, 4));
    edges.push_back(make_pair(0, 1));
    edges.push_back(make_pair(1, 2));

    unordered_map<int, list<int>> adj;

    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int timer = 0;
    vector<int> disc(n, -1);
    vector<int> low(n, -1);
    unordered_map<int, bool> vis;
    vector<int> ap(n, 0);

    for (int i = 0; i < n; i++) {
        if (vis[i] == false) {
            DFS(i, -1, disc, low, vis, adj, ap, timer);
        }
    }

    cout << "articulation points are as follows:" << ap.size() << endl;
    for (int i = 0; i < ap.size(); i++) {
        if (ap[i] == true) cout << i << " ";
    }
    cout << endl;
    return 0;
}