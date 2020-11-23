#include <bits/stdc++.h>
using namespace std; 
void dfs(int s, vector <int> adj[], int visited[], int currentAmountOfComponents){
    if(visited[s] != 0) return;
    visited[s] = currentAmountOfComponents;
    for(auto u: adj[s]){
        dfs(u, adj, visited, currentAmountOfComponents);
    }
}


int main(){
    int n;
    cin >> n;
    vector <int> adj[n];
    int visited[n];
    for(int i = 0; i < n; i++) visited[i] = 0;
    int amountOfEdges;
    cin >> amountOfEdges;
    for(int i = 0; i < amountOfEdges; i++){
        int begin, end;
        cin >> begin >> end;
        adj[begin - 1].push_back(end - 1);
        adj[end - 1].push_back(begin - 1);
    }
    int currentAmountOfComponents = 1;
    for(int i = 0; i < n; i++){
        if(adj[i].size() == 0) {
            visited[i] = currentAmountOfComponents;
            currentAmountOfComponents ++;
        }
    }
    bool isConnective = false;
    while(!isConnective){
        int start;
        for(int i = 0; i < n; i++){
            if(visited[i] == 0) {start = i; break;}
        }
        dfs(start, adj, visited, currentAmountOfComponents);
        isConnective = true;
        for(int i = 0; i < n; i++){
            if(visited[i] == 0) isConnective = false;
        }
        currentAmountOfComponents += (int)(!isConnective);
    }
    cout << currentAmountOfComponents;
}