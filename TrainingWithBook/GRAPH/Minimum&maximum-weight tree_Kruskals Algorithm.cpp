#include <bits/stdc++.h>
using namespace std; 

bool same(int a, int b, int components[]){
    return components[a] == components[b];
}

void unite(int a, int b, int n, int components[]){
    int x = components[b];
    for(int i = 0; i < n; i++){
        if(components[i] == x) components[i] = components[a];
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    vector <tuple<int, int, int>> edges;
    for(int i = 0; i < m; i++){
        int a, b, w;
        cin >> a >> b >> w;
        edges.push_back({w, a-1, b-1});
    }
    int components[n];
    for(int i = 0; i < n; i++) components[i] = i;
    vector <tuple <int, int, int>> usedEdges;
    sort(edges.begin(), edges.end());//if we want to get maximum-weight tree, we shall change 'begin' to 'rbegin' & 'end' to 'rend'
    for(int i = 0; i < m; i++){
        int a, b, w;
        tie(w, a, b) = edges[i];
        if(!same(a, b, components)){
            unite(a, b, n, components);
            usedEdges.push_back({w, a, b});
        }
    }
    int summaryWeight = 0;
    for(auto u: usedEdges){
        int a, b, w;
        tie(w, a, b) = u;
        summaryWeight += w;
        cout << a+1 << " " << b+1 <<  " " << w << '\n';
    }
    cout << summaryWeight;
}
/* 
6 8    
1 2 3
1 5 5
2 5 6
2 3 5
3 4 9
4 6 7
3 6 3
5 6 2
 */