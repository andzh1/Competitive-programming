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

void componentSearchDFS(int s, vector <int> adj[], int matchOfVertexesAndComponents[], int currentAmountOfComponents){
    if(matchOfVertexesAndComponents[s] != 0) return;
    matchOfVertexesAndComponents[s] = currentAmountOfComponents;
    for(auto u: adj[s]){
        componentSearchDFS(u, adj, matchOfVertexesAndComponents, currentAmountOfComponents);
    }
}
//dfs, which 'returns' in which component each vertex is

void bfs(int s, vector <int> adj[], bool visited[], int distance[]){
    distance[s] = 0;
    queue <int> queueOfVertexes;
    visited[s] = true;
    queueOfVertexes.push(s); 
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
//classic breath-first search. adj[] - array of adjacencies; distance[i] - distance between starting vertex s and i; 

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

int findingAmountOfConnectivityComponents(int n, vector <int> adj[]){
    int matchOfVertexesAndComponents[n];
    for(int i = 0; i < n; i++) matchOfVertexesAndComponents[i] = 0;
    int currentAmountOfComponents = 1;
    for(int i = 0; i < n; i++){
        if(adj[i].size() == 0) {
            matchOfVertexesAndComponents[i] = currentAmountOfComponents;
            currentAmountOfComponents ++;
        }
    }
    bool isConnective = false;
    while(!isConnective){
        int start;
        for(int i = 0; i < n; i++){
            if(matchOfVertexesAndComponents[i] == 0) {start = i; break;}
        }
        componentSearchDFS(start, adj, matchOfVertexesAndComponents, currentAmountOfComponents);
        isConnective = true;
        for(int i = 0; i < n; i++){
            if(matchOfVertexesAndComponents[i] == 0) isConnective = false;
        }
        currentAmountOfComponents += (int)(!isConnective);
    }
    return currentAmountOfComponents;
}
//returns amount of connectivity components in graph
void findMatchOfVertexesAndComponents(int n, vector <int> adj[], int matchOfVertexesAndComponents[]){
    // for(int i = 0; i < n; i++) matchOfVertexesAndComponents[i] = 0;
    int currentAmountOfComponents = 1;
    for(int i = 0; i < n; i++){
        if(adj[i].size() == 0) {
            matchOfVertexesAndComponents[i] = currentAmountOfComponents;
            currentAmountOfComponents ++;
        }
    }
    bool isConnective = false;
    int start = 0;
    while(!isConnective){
        for(int i = start; i < n; i++){
            if(matchOfVertexesAndComponents[i] == 0) {start = i; break;}
        }
        componentSearchDFS(start, adj, matchOfVertexesAndComponents, currentAmountOfComponents);
        isConnective = true;
        for(int i = 0; i < n; i++){
            if(matchOfVertexesAndComponents[i] == 0) isConnective = false;
        }
        currentAmountOfComponents += (int)(!isConnective);
    }
}

void getAllComponents(int n, vector <int> adj[], vector <int> components[]){
    int matchOfVertexesAndComponents[n];
    for(auto u:matchOfVertexesAndComponents) u = 0;
    findMatchOfVertexesAndComponents(n, adj, matchOfVertexesAndComponents);
    for(int ip = 0; ip < n; ip++){
        components[matchOfVertexesAndComponents[ip] - 1].push_back(ip);
    }
}



int main(){
    int n;
    cin >> n;
    vector <int> adj[n];
    bool visited[n];
    int matchOfVertexesAndComponents[n];
    for(int i = 0; i < n; i++) {
        visited[i] = false;
        matchOfVertexesAndComponents[i] = 0;
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
    int amountOfComponents = findingAmountOfConnectivityComponents(n, adj);
    vector <int> components[amountOfComponents];
    findMatchOfVertexesAndComponents(n, adj, matchOfVertexesAndComponents);
    getAllComponents(n, adj, components);
    // for(int ip = 0; ip < n; ip++){
    //     components[matchOfVertexesAndComponents[ip] - 1].push_back(ip);
    // }
    for(int i = 0; i < amountOfComponents; i++){
        cout << i+1 << " component - {";
        for(auto u: components[i]) cout << u << ";";
        cout << "}" << '\n';
    }
    
}