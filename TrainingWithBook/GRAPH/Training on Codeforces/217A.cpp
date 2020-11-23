#include <bits/stdc++.h>
using namespace std; 
//https://codeforces.com/problemset/problem/217/A

void dfa(int start, vector <int> adj[], int visited[], int currentComponent){
    if(visited[start] > 0) return;
    visited[start] = currentComponent;
    for(auto x: adj[start]){
        dfa(x, adj, visited, currentComponent);
    }
}

int main(){
    int n;
    cin >> n;
    pair <int, int> points[n];
    for(int i = 0; i < n; i++){
        cin >> points[i].first >> points[i].second;
    }
    vector <int> adj[n];
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if((points[i].first == points[j].first) || (points[i].second == points[j].second)){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    int amountOfComponents = 1;
    int visited[n];
    for(int i = 0; i < n; i++){
        if(adj[i].empty()) {
            visited[i] = amountOfComponents;
            amountOfComponents ++;
        }
        else visited[i] = 0;
    }
    for(int i = 0; i < n - amountOfComponents; i++){
        int start = -1;
        for(int j = 0; j < n; j++){
            if(visited[j] == 0) {start = j; break;}
        }
        if(start >= 0){
            dfa(start, adj, visited, amountOfComponents);
            amountOfComponents ++;
        } else break;
    }
    cout << amountOfComponents - 2 << '\n';

}
