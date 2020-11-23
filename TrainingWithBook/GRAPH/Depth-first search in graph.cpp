#include <bits/stdc++.h>
using namespace std; 
void dfs(int s, vector <int> adj[], bool visited[], int counter, int n){
    if(visited[s]) return;
    visited[s] = true;
    //operating with S
    for(auto u: adj[s]){
        dfs(u, adj, visited, counter, n);
    }
}



int main(){
    int n;
    cin >> n;
    vector <int> adj[n];
    bool visited[n];
    for(int i = 0; i < n; i++) visited[i] = false;
    int amountOfEdges;
    cin >> amountOfEdges;
    for(int i = 0; i < amountOfEdges; i++){
        int begin, end;
        cin >> begin >> end;
        adj[begin - 1].push_back(end - 1);
    }
    int counter = 0;
    dfs(0, adj, visited, counter, n);
}