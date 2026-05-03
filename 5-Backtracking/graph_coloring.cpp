#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool isSafeColor(int v, vector<vector<int>>& graph, vector<int>& color,
                 int c, int V) {
    for (int u = 0; u < V; u++) {
        // If u is adjacent to v and has the same color, not safe
        if (graph[v][u] == 1 && color[u] == c)
            return false;
    }
    return true;
}

bool graphColorUtil(int v, vector<vector<int>>& graph, int m,
                    vector<int>& color, int V) {
    if (v == V) return true; // All vertices colored

    for (int c = 1; c <= m; c++) {
        if (isSafeColor(v, graph, color, c, V)) {
            color[v] = c;

            if (graphColorUtil(v + 1, graph, m, color, V))
                return true;

            color[v] = 0; // Backtrack
        }
    }
    return false;
}

void graphColoring(int V, int m, vector<vector<int>>& graph) {
    vector<int> color(V, 0);

    if (!graphColorUtil(0, graph, m, color, V)) {
        cout << "  No solution exists with " << m << " colors.\n";
        return;
    }

    cout << "  Color assignment (vertex: color):\n  ";
    for (int i = 0; i < V; i++)
        cout << "V" << i << ":" << color[i] << "  ";
    cout << endl;
}

int main() {
    cout << "\n========== GRAPH COLORING ==========\n";
    int V = 4, m = 3;
    // Adjacency matrix
    vector<vector<int>> graph = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}
    };
    cout << "  Vertices: " << V << " | Colors available: " << m << "\n";
    cout << "  Edges: (0-1),(0-2),(0-3),(1-2),(2-3)\n";
    graphColoring(V, m, graph);
}