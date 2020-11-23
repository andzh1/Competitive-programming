#include <bits/stdc++.h>
using namespace std; 
void dfs(int s, vector <int> adj[], bool visited[]){
    if(visited[s]) return;
    visited[s] = true;
    for(auto u: adj[s]){
        dfs(u, adj, visited);
    }
}

void bfs(int s, vector <int> adj[], bool visited[], int distance[], queue <int> queueOfVertexes){
    while(!queueOfVertexes.empty()){
        int s = queueOfVertexes.front();
        queueOfVertexes.pop();
        for(auto u: adj[s]){
            if(visited[u]) continue;
            visited[u] = true;
            distance[u] = distance[s] + 1;
            queueOfVertexes.push(u);
        }
    }
}

bool chechIfConnective(int n, vector <int> adj[], bool visited[]){
    dfs(0, adj, visited);
    bool isConnective = true;
    for(int i = 0; i < n; i++){
        if(!visited[i]) isConnective = false;
    }
    if(isConnective) return true;
    else return false;
}

int main(){
    int n;
    cin >> n;
    vector <int> adj[n];
    bool visited[n];
    for(int i = 0; i < n; i++) visited[i] = false;
    //reading list of adjacencies
    int amountOfEdges;
    cin >> amountOfEdges;
    for(int i = 0; i < amountOfEdges; i++){
        int begin, end;
        cin >> begin >> end;
        adj[begin - 1].push_back(end - 1);
        adj[end - 1].push_back(begin - 1);
    }

    //starting dfs
    dfs(0, adj, visited);
    bool isConnective = true;
    for(int i = 0; i < n; i++){
        if(!visited[i]) isConnective = false;
    }
    if(isConnective) cout << "Is connective";
    else cout << "Is disconnective";
    
}