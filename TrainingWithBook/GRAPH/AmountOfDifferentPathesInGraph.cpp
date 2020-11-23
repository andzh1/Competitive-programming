#include <bits/stdc++.h>
using namespace std; 

int Search4Pathes(int x, vector <int> adj[], int* path, bool visited[]){
    if(visited[x]) return path[x];
    else 
    {
        visited[x] = true;
        for(auto b : adj[x]){
            path[x] += Search4Pathes(b, adj, path, visited);
        }
        return path[x];
    }
}



int main(){
    int n;
    cin >> n;
    int amountOfEdges;
    cin >> amountOfEdges;
    vector <int> adjOut[n]; //adjOut[i] = vector of pairs, each pair contains {j,w}: j - number of vertex, which is an ending of edge {i,j}, w - weight of this edge
    vector <int> adjIn[n]; //adjIn[i] = vector of pairs, each pair contains {j,w}: j - number of vertex, which is a beginning of edge {j,i}, w - weight of this edge
    
    for(int i = 0; i < amountOfEdges; i++){
        int a,b;
        cin >> a >> b;
        adjIn[b-1].push_back(a-1);
        adjOut[a-1].push_back(b-1); 
    }
    bool visited[n];
    int path[n];
    for(int i = 0; i < n; i++) {
        path[i] = 0;
        visited[i] = false;
    }

    int start, finish;
    cin >> start >> finish;

    path[start - 1] = 1;
    visited[start - 1] = true;
    cout << Search4Pathes(finish - 1, adjIn, path, visited);
}
