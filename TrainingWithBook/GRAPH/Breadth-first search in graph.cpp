#include <bits/stdc++.h>
using namespace std; 
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

    int distance[n];
    int start = 0;
    distance[start] = 0;
    queue <int> queueOfVertexes;
    visited[start] = true;
    distance[start] = 0;
    queueOfVertexes.push(start);
    
    bfs(start, adj, visited, distance, queueOfVertexes);
    for(int i = 0; i < n; i++) cout << distance[i] << " ";
    
}