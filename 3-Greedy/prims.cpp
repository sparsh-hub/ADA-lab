#include <bits/stdc++.h>
using namespace std;
#include <chrono>

#define INF INT_MAX

int primMST(vector<vector<pair<int,int>>>& graph, int V) {
    vector<int> key(V, INF);
    vector<bool> inMST(V, false);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;

    key[0] = 0;
    pq.push({0, 0});
    int totalWeight = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (inMST[u]) continue;
        inMST[u] = true;
        totalWeight += key[u];

        for (auto& [weight, v] : graph[u]) {
            if (!inMST[v] && weight < key[v]) {
                key[v] = weight;
                pq.push({key[v], v});
            }
        }
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

        // Build a complete graph with random-ish weights
        vector<vector<pair<int,int>>> graph(V);
        for (int i = 0; i < V; i++)
            for (int j = i + 1; j < V; j++) {
                int w = (i + j) % 10 + 1;
                graph[i].push_back({w, j});
                graph[j].push_back({w, i});
            }

        auto start = chrono::high_resolution_clock::now();
        primMST(graph, V);
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