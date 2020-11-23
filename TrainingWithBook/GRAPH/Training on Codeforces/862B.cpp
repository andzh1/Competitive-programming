#include <bits/stdc++.h>
using namespace std; 
//https://codeforces.com/problemset/problem/862/B

void paintIn2Colors(int start, vector <int> adj[], bool isBlack, bool colors[], bool visited[]){
    if(visited[start]) return;
    visited[start] = true;
    colors[start] = isBlack;
    for(auto x: adj[start]){
        paintIn2Colors(x, adj, !isBlack, colors, visited);
    }
}

int main(){
    long long n;
    cin >> n;
    vector <int> adj[n];
    long long a, b;
    for(int i = 0; i < n - 1; i ++){
        cin >> a >> b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }
    bool isBlack = true;
    bool colors[n];
    bool visited[n];
    for(int i = 0; i < n; i++) visited[i] = false;
    paintIn2Colors(0, adj, isBlack, colors, visited);
    long long amount = 0;
    for(int i = 0; i < n; i++) amount += colors[i];
    long long answer = n*(n-1)/2 - (amount-1)*amount/2 - (n-1) - (n-amount)*(n-amount-1)/2;
    cout << answer << '\n';
    // for(int i = 0; i < n; i++) visited[i] = false;

}
