#include <bits/stdc++.h>
using namespace std; 
void componentSearchDFS(int s, vector <int> adj[], int matchOfVertexesAndComponents[], int currentAmountOfComponents){
    if(matchOfVertexesAndComponents[s] != 0) return;
    matchOfVertexesAndComponents[s] = currentAmountOfComponents;
    for(auto u: adj[s]){
        componentSearchDFS(u, adj, matchOfVertexesAndComponents, currentAmountOfComponents);
    }
}

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
    for(int ip = 0; ip < n; ip++){
        components[matchOfVertexesAndComponents[ip] - 1].push_back(ip);
    }
    for(int i = 0; i < amountOfComponents; i++){
        cout << "Сomponent " << i+1 << " - {";
        for(auto u: components[i]) cout << u << ";";
        cout << "}" << '\n';
    }
    
}