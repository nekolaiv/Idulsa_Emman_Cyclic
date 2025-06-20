#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool isCyclic(vector<vector<int>>& graph) {
    int V = graph.size();
    vector<int> indegree(V, 0);

    for (int u = 0; u < V; u++)
        for (int v = 0; v < V; v++)
            if (graph[u][v])
                indegree[v]++;

    queue<int> q;
    for (int i = 0; i < V; i++)
        if (indegree[i] == 0)
            q.push(i);

    int count = 0;
    while (!q.empty()) {
        int node = q.front(); q.pop();
        count++;

        for (int v = 0; v < V; v++) {
            if (graph[node][v]) {
                indegree[v]--;
                if (indegree[v] == 0)
                    q.push(v);
            }
        }
    }

    return (count != V);
}

int main() {
    int V;
    cout << "Enter number of vertices (max 26): ";
    cin >> V;

    vector<vector<int>> graph(V, vector<int>(V));
    cout << "Enter the adjacency matrix (use 0 or 1):\n";
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            cin >> graph[i][j];

    if (isCyclic(graph)) {
        cout << "Cycle detected in the graph." << endl;
    } else {
        cout << "No cycle found in the graph." << endl;
    }

    return 0;
}
