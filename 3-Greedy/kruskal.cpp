#include <bits/stdc++.h>
using namespace std;
#include <chrono>

struct Edge {
    int u, v, weight;
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

struct DSU {
    vector<int> parent, rank_;
    DSU(int n) : parent(n), rank_(n, 0) {
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }
    bool unite(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return false;
        if (rank_[px] < rank_[py]) swap(px, py);
        parent[py] = px;
        if (rank_[px] == rank_[py]) rank_[px]++;
        return true;
    }
};

int kruskalMST(vector<Edge>& edges, int V) {
    sort(edges.begin(), edges.end());
    DSU dsu(V);
    int totalWeight = 0;

    for (auto& e : edges) {
        if (dsu.unite(e.u, e.v))
            totalWeight += e.weight;
    }
    return totalWeight;
}

int main() {
    int n;
    cin >> n;
    int t = n;

    vector<long long> durationArray(n + 1);

    cout << "value of n (vertices)     ->     time taken" << endl;

    while (n > 0) {
        int V = n;

        // Build a complete graph with edges
        vector<Edge> edges;
        for (int i = 0; i < V; i++)
            for (int j = i + 1; j < V; j++)
                edges.push_back({i, j, (i + j) % 10 + 1});

        auto start = chrono::high_resolution_clock::now();
        kruskalMST(edges, V);
        auto stop = chrono::high_resolution_clock::now();

        auto duration = chrono::duration_cast<chrono::nanoseconds>(stop - start);
        durationArray[n] = duration.count();

        cout << "     " << n
             << "         ->      "
             << duration.count()
             << " nanoseconds" << endl;

        n--;
    }

    long long sum = 0;
    for (auto time : durationArray) sum += time;

    long long avg = sum / t;
    cout << "the average time taken to execute the program is "
         << avg << " nanoseconds";

    return 0;
}




    cout << "Shortest paths from node " << src << ":\n";
    for (int i = 0; i < n; i++) {
        cout << "To " << i << " (cost " << cost[i] << "): ";
        if (path[i].empty())
            cout << "can't reach";
        else {
            for (int j = 0; j < path[i].size(); j++) {
                if (j) cout << " -> ";
                cout << path[i][j];
            }
        }
        cout << "\n";
    }
}

int main() {
    int n = 6; 
    vector<vector<pair<int,int>>> adj(n); 

    auto addEdge = [&](int u, int v, int w) {
        adj[u].push_back({w, v});
        adj[v].push_back({w, u}); 
    };

    addEdge(0, 1, 4);
    addEdge(0, 2, 1);
    addEdge(2, 1, 2);
    addEdge(1, 3, 1);
    addEdge(2, 3, 5);
    addEdge(3, 4, 3);
    addEdge(4, 5, 2);

    dijkstra(0, n, adj);

    return 0;
}