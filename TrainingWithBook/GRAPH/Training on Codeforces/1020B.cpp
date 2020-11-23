#include <bits/stdc++.h>
using namespace std; 
//https://codeforces.com/problemset/problem/1020/B

void dfa(int start, vector <int> adj[], bool visited[]){
    if(visited[start]) {
        cout << start+1 << " ";
        return;
    }
    visited[start] = true;
    for(auto x: adj[start]){
        dfa(x, adj, visited);
    }
}

int main(){
    int n;
    cin >> n;
    vector <int> adj[n];
    int x;
    for(int i = 0; i < n; i++) 
    {
        cin >> x;
        adj[i].push_back(x-1);
    }
    bool visited[n];
    
    for(int t = 0; t < n; t++) {
        for(int i = 0; i < n; i++) visited[i] = 0;
        dfa(t, adj, visited);
    }   
}
