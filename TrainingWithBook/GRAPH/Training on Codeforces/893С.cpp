#include <bits/stdc++.h>
using namespace std; 
//https://codeforces.com/problemset/problem/893/С

void dfa(int start, vector <int> adj[], int visited[], int currentAmountOfComponents)
{
    if(visited[start] != 0) return;
    visited[start] = currentAmountOfComponents;
    for(auto x: adj[start]){
        dfa(x, adj, visited, currentAmountOfComponents);
    }
}
int main(){
    int n, m;
    cin >> n >> m;
    int values[n];
    for(int i = 0; i < n; i++){
        cin >> values[i];
    }
    vector <int> adj[n];
    int a, b;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }
    int start = -1, currentAmountOfComponents = 1;
    long long summ = 0;
    int visited[n];
    for(int i = 0; i < n; i++) {
        if(adj[i].size() == 0) {
            visited[i] = currentAmountOfComponents;
            currentAmountOfComponents ++;
            summ += values[i];
        } else {
            visited[i] = 0;
            start = i;
        }
    }
    
    while(start >= 0){
        dfa(start, adj, visited, currentAmountOfComponents);
        int minimum = INT32_MAX;
        start = -1;
        for(int i = 0; i < n; i++){
            if(visited[i] == currentAmountOfComponents)
                minimum = min(minimum, values[i]);
            if(visited[i] == 0) start = i;
        }
        summ += minimum;
        currentAmountOfComponents ++;
    }
    cout << summ << '\n';
       
}
