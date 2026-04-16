#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, int>& a,pair<int, int>& b) {
        if (a.second==b.second) return a.first>b.first;
        else return a.second<b.second;
    }

int sorting_by_weights(vector<pair<int, int>>& items, int n, int M) {
    sort(items.begin(), items.end(), compare);
    int total_profit=0;
    
    for (int i=0; i<n; i++) {
        if (M>=items[i].second) {
            total_profit+= items[i].first;
            M-= items[i].second;
        } 
    }
    
    return total_profit;
    
}


int sorting_by_profits_weights(vector<pair<int, int>> &items, int n, int M){
    int total_profit = 0;
    for(int i = 0; i < n; i++){
        
    }
}



int main() {
    vector<pair<int, int>> items={{10, 20}, {5, 10}, {6, 15}, {15, 5}, {10, 2}};
    int M=20;
    int n=5;
    auto start = chrono::high_resolution_clock::now();
    int ans1=sorting_by_weights(items, n, M);
    int ans2=sorting_by_profits(items, n, M);
    int ans3=sorting_by_weights_and_profits(items, n, M);
    auto end = chrono::high_resolution_clock::now();
    cout << chrono::duration<double,micro>(end-start) << endl;
    cout << ans1 << " " << ans2 << " " << ans3 << " " << endl;
}
