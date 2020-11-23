#include <bits/stdc++.h>
using namespace std; 
//https://codeforces.com/problemset/problem/330/B


int main(){
    int n, m;
    cin >> n >> m;
    vector <int> adj[n]; 
    int a, b;
    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }
    int ip = -1;
    for(int i = 0; i < n; i++){
        if(adj[i].size() == 0) ip = i;
    }
    cout << n-1 << '\n';
    for(int i = 0; i < n; i++){
        if(i != ip) cout << ip + 1 << " " << i + 1 << '\n';
    }
}
