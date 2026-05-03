#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;



bool isSafeHam(int v, vector<vector<int>>& graph, vector<int>& path,
               int pos, int V) {
    // Must be an edge from last vertex in path to v
    if (graph[path[pos - 1]][v] == 0) return false;

    // v must not already be in path
    for (int i = 0; i < pos; i++)
        if (path[i] == v) return false;

    return true;
}

bool hamiltonianUtil(vector<vector<int>>& graph, vector<int>& path,
                     int pos, int V) {
    if (pos == V) {
        // Check if there's an edge from last vertex back to start
        return graph[path[pos - 1]][path[0]] == 1;
    }

    for (int v = 1; v < V; v++) {
        if (isSafeHam(v, graph, path, pos, V)) {
            path[pos] = v;

            if (hamiltonianUtil(graph, path, pos + 1, V))
                return true;

            path[pos] = -1; // Backtrack
        }
    }
    return false;
}

void hamiltonianCycle(int V, vector<vector<int>>& graph) {
    vector<int> path(V, -1);
    path[0] = 0; // Start from vertex 0

    if (!hamiltonianUtil(graph, path, 1, V)) {
        cout << "  No Hamiltonian Cycle exists.\n";
        return;
    }

    cout << "  Hamiltonian Cycle: ";
    for (int i = 0; i < V; i++)
        cout << path[i] << " -> ";
    cout << path[0] << endl; // Return to start
}

void run_hamiltonian() {
    cout << "\n========== HAMILTONIAN CYCLE ==========\n";
    int V = 5;
    vector<vector<int>> graph = {
        {0, 1, 0, 1, 0},
        {1, 0, 1, 1, 1},
        {0, 1, 0, 0, 1},
        {1, 1, 0, 0, 1},
        {0, 1, 1, 1, 0}
    };
    cout << "  Vertices: " << V << "\n";
    hamiltonianCycle(V, graph);
}