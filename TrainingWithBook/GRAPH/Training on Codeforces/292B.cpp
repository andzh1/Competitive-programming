#include <bits/stdc++.h>
using namespace std; 
//https://codeforces.com/problemset/problem/292/B


int main(){
    int n, m;
    cin >> n >> m;
    vector <int> adj[n];
    int x, y;
    for(int i = 0; i < m; i++){
        cin >> x >> y;
        adj[x-1].push_back(y-1);
        adj[y-1].push_back(x-1);
    }
    // bool isCycle = true;
    int amountOfLeafs = 0, amountOf2 = 0;
    for(int i = 0; i < n; i++){
        // if(adj[i].size() != 2) isCycle = false;
        if(adj[i].size() == 1) amountOfLeafs++;
        if(adj[i].size() == 2) amountOf2++;
    }
    if(amountOf2 == n) cout << "ring topology\n"; 
    else
    {
        if(amountOfLeafs == 2 && amountOf2 == n - 2) cout << "bus topology\n";
        else if(amountOfLeafs == n - 1) cout << "star topology\n";
        else cout << "unknown topology\n";
    }
       
}
