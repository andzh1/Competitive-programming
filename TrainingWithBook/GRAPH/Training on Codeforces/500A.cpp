#include <bits/stdc++.h>
using namespace std; 
//https://codeforces.com/problemset/problem/500/A

void dfa(int start, vector <int> adj[], bool visited[]){
    if(visited[start]) return;
    visited[start] = true;
    for(auto x: adj[start]){
        dfa(x, adj, visited);
    }
}

int main(){
    int n, t;
    cin >> n >> t;
    vector <int> adj[n];
    int x;
    for(int i = 1; i < n; i++) 
    {
        cin >> x;
        adj[i - 1].push_back(i + x-1);
    }
    bool visited[n];
    for(int i = 0; i < n; i++) visited[i] = 0;
    dfa(0, adj, visited);
    if(visited[t-1]) cout << "YES";
    else cout << "NO";
}
