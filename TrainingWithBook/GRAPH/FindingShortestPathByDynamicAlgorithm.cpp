#include <bits/stdc++.h>
using namespace std; 

int Search4ShortestPath(int x, vector <pair <int, int>> adj[], int* path, bool visited[]){
    if(visited[x]) return path[x];
    else 
    {
        visited[x] = true;
        for(auto y : adj[x]){
            int b = y.first;
            int w = y.second;
            path[x] = min(path[x], Search4ShortestPath(b, adj, path, visited) + w);
        }
        return path[x];
    }
}



int main(){
    int n;
    cin >> n;
    int amountOfEdges;
    cin >> amountOfEdges;
    vector <pair <int, int>> adjOut[n]; //adjOut[i] = vector of pairs, each pair contains {j,w}: j - number of vertex, which is an ending of edge {i,j}, w - weight of this edge
    vector <pair <int, int>> adjIn[n]; //adjIn[i] = vector of pairs, each pair contains {j,w}: j - number of vertex, which is a beginning of edge {j,i}, w - weight of this edge
    
    for(int i = 0; i < amountOfEdges; i++){
        int a,b,w;
        cin >> a >> b >> w;
        adjIn[b-1].push_back({a-1,w});
        adjOut[a-1].push_back({b-1,w});
    }

    int path[n];
    bool visited[n];
    for(int i = 0; i < n; i++) {
        path[i] = INT32_MAX;
        visited[i] = false;
    }

    int start, finish;
    cin >> start >> finish;

    path[start - 1] = 0;
    visited[start - 1] = true;

    cout << Search4ShortestPath(finish - 1, adjIn, path, visited);
}
