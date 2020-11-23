#include <bits/stdc++.h>
using namespace std; 
void dfs(int s, vector <int> adj[], bool visited[]){
    if(visited[s]) return;
    visited[s] = true;
    for(auto u: adj[s]){
        dfs(u, adj, visited);
    }
}
//classic depth-first search

void componentSearchDFS(int s, vector <int> adj[], int components[], int currentAmountOfComponents){
    if(components[s] != 0) return;
    components[s] = currentAmountOfComponents;
    for(auto u: adj[s]){
        componentSearchDFS(u, adj, components, currentAmountOfComponents);
    }
}
//dfs, which returns in which component each vertex is

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
//classic breath-first search

bool checkIfConnective(int n, vector <int> adj[], bool visited[]){
    dfs(0, adj, visited);
    bool isConnective = true;
    for(int i = 0; i < n; i++){
        if(!visited[i]) isConnective = false;
    }
    if(isConnective) return true;
    else return false;
}
//returns true, if graph is connective, & false if it isn't

int findingAmountOfConnectivityComponents(int n, vector <int> adj[], int components[]){
    int currentAmountOfComponents = 1;
    for(int i = 0; i < n; i++){
        if(adj[i].size() == 0) {
            components[i] = currentAmountOfComponents;
            currentAmountOfComponents ++;
        }
    }
    bool isConnective = false;
    while(!isConnective){
        int start;
        for(int i = 0; i < n; i++){
            if(components[i] == 0) {start = i; break;}
        }
        componentSearchDFS(start, adj, components, currentAmountOfComponents);
        isConnective = true;
        for(int i = 0; i < n; i++){
            if(components[i] == 0) isConnective = false;
        }
        currentAmountOfComponents += (int)(!isConnective);
    }
    return currentAmountOfComponents;
}
//returns amount of connectivity components in graph

bool searchForLoops(int n, )


int main(){
    int n;
    cin >> n;
    vector <int> adj[n];
    bool visited[n];
    int components[n];
    for(int i = 0; i < n; i++) {
        visited[i] = false;
        components[i] = 0;
    }
    //reading list of adjacencies
    int amountOfEdges;
    cin >> amountOfEdges;
    for(int i = 0; i < amountOfEdges; i++){
        int begin, end;
        cin >> begin >> end;
        adj[begin - 1].push_back(end - 1);
        adj[end - 1].push_back(begin - 1);
    }
    cout << checkIfConnective(n, adj, visited);

    // int distance[n];
    // int start = 0;
    // distance[start] = 0;
    // queue <int> queueOfVertexes;
    // visited[start] = true;
    // distance[start] = 0;
    // queueOfVertexes.push(start); 
    // bfs(start, adj, visited, distance, queueOfVertexes);   
    
}