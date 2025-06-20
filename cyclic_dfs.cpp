#include <iostream>
#include <vector>

using namespace std;

bool dfs(int node, vector<vector<int>>& graph, vector<bool>& visited, vector<bool>& recStack, vector<int>& path) {
    visited[node] = true;
    recStack[node] = true;
    path.push_back(node);

    for (int i = 0; i < graph.size(); i++) {
        if (graph[node][i]) {
            if (!visited[i] && dfs(i, graph, visited, recStack, path))
                return true;
            else if (recStack[i]) {
                path.push_back(i);  // cycle closes
                return true;
            }
        }
    }

    path.pop_back();
    recStack[node] = false;
    return false;
}

bool isCyclic(vector<vector<int>>& graph, vector<int>& cyclePath) {
    int V = graph.size();
    vector<bool> visited(V, false), recStack(V, false);

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, graph, visited, recStack, cyclePath))
                return true;
        }
    }
    return false;
}

int main() {
    int V;
    cout << "Enter number of vertices (max 26): ";
    cin >> V;

    vector<vector<int>> graph(V, vector<int>(V));
    cout << "Enter the adjacency matrix (use 0 or 1):\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> graph[i][j];
        }
    }

    vector<int> cyclePath;
    if (isCyclic(graph, cyclePath)) {
        cout << "Cycle detected: ";
        for (int v : cyclePath)
            cout << (char)('A' + v) << " ";
        cout << endl;
    } else {
        cout << "No cycle found." << endl;
    }

    return 0;
}
