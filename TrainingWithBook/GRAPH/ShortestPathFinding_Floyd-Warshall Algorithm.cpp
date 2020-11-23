#include <bits/stdc++.h>
using namespace std; 

int da(int start, int finish, int n, vector <pair <int,int>> adj[])
{
    priority_queue <pair <int,int>> q;
    int distance[n];
    bool proceed[n];
    for(int i = 0; i < n; i++) {
        distance[i] = INT32_MAX;
        proceed[i] = false;
    }
    distance[start] = 0;
    q.push({0, start});
    while(!q.empty()){
        int a = q.top().second;
        q.pop();
        if(proceed[a]) continue;
        proceed[a] = true;
        for(auto u: adj[a]){
            int b = u.first, w = u.second;
            if(distance[a] + w < distance[b]){
                distance[b] = distance[a] + w;
                q.push({-distance[b], b});
            }
        }
    }
    return distance[finish];
}
//Works, if graph doesn't contain edges with negative weight


int main(){
    int n;
    cin >> n;
    int amountOfEdges;
    cin >> amountOfEdges;
    int adj[n][n];
    for(int i = 0; i < amountOfEdges; i++){
        int a,b,w;
        cin >> a >> b >> w;
        adj[a-1][b-1] = w;
        adj[b-1][a-1] = w;
    }
    int start, finish;
    cin >> start >> finish;
    cout << da(start - 1, finish - 1, n, adj);
}
