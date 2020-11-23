#include <bits/stdc++.h>
using namespace std; 
//https://codeforces.com/problemset/problem/707/B



int main(){
    int n, m, k;
    cin >> n >> m >> k;
    vector <pair <int, int>> adj[n]; 
    int a, b, w;
    for(int i = 0; i < m; i++) {
        cin >> a >> b >> w;
        adj[a-1].push_back({b-1, w});
        adj[b-1].push_back({a-1, w});
    }
    bool hasAStorage[n];
    int storages[k];
    for(int i = 0; i < n; i++) hasAStorage[i] = false;
    for(int i = 0; i < k; i++) {
        cin >> storages[i];
        storages[i] --;
        hasAStorage[storages[i]] = true;
    }
    int minimum = INT32_MAX;
    for(int i = 0; i < k; i++){
        int localMin = INT32_MAX;
        for(auto x: adj[storages[i]]){
            int b = x.first, w = x.second;
            if(!hasAStorage[b]) {
                localMin = min(localMin, w);
            } 
        }
        minimum = min(minimum, localMin);
    }
    if(minimum == INT32_MAX) cout << "-1\n";
    else cout << minimum << '\n';
}
