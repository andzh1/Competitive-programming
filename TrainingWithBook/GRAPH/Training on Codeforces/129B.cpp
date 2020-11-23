#include <bits/stdc++.h>
using namespace std; 
//https://codeforces.com/problemset/problem/129/B


int main(){
    int TT;
    cin >> TT;
    for(int UU = 0; UU < TT; UU++){
        int n, m;
        cin >> n >> m;
        vector <int> adj[n];
        int x, y;
        for(int i = 0; i < m; i++){
            cin >> x >> y;
            adj[x-1].push_back(y-1);
            adj[y-1].push_back(x-1);
        }
    }
}
