#include <bits/stdc++.h>
using namespace std; 
//https://codeforces.com/problemset/problem/1055/A

void dfa(int start, vector <int> adj[], bool visited[]){
    if(visited[start]) return;
    visited[start] = true;
    for(auto x: adj[start]){
        dfa(x, adj, visited);
    }
}

int main(){
    int n, s;
    cin >> n >> s;
    int firstRoad[n], secondRoad[n];
    for(int i = 0; i < n; i++) cin >> firstRoad[i];
    for(int i = 0; i < n; i++) cin >> secondRoad[i];
    if(firstRoad[0] == 0) cout << "NO";
    else 
    {
        vector <int> adj[n];
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++){
                if(firstRoad[i] == 1 && firstRoad[j] == 1) adj[i].push_back(j);
                if(secondRoad[i] == 1 && secondRoad[j] == 1) adj[j].push_back(i);
            }
        }
        bool visited[n];
        for(int i = 0; i < n; i++) visited[i] = false;
        dfa(0, adj, visited);
        if(visited[s-1]) cout << "YES";
        else cout << "NO";
    }
    
}
