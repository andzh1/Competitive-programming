#include <bits/stdc++.h>
using namespace std; 

int bfa(int start, int finish, int n, vector <tuple <int,int,int>> edges)
{
    int distance[n];
    for(int i = 0; i < n; i++) distance[i] = INT32_MAX;
    distance[start] = 0;
    for(int i = 1; i <= n - 1; i++){
        for(auto e : edges) {
            int a, b, w;
            tie(a,b,w) = e;
            distance[b] = min(distance[b], distance[a] + w);
        }
    }
    return distance[finish];
}
//Works, if graph doesn't contain loops with negative length

//If we'll do n operations instead of n-1 in our algorithm, & any distance will increase, 
// that 'll mean that graph contains at least 1 loop with negative length

int main(){
    int n;
    cin >> n;
    int amountOfEdges;
    cin >> amountOfEdges;
    vector <tuple <int, int, int>> edges;
    for(int i = 0; i < amountOfEdges; i++){
        int a,b,w;
        cin >> a >> b >> w;
        edges.push_back({a-1,b-1,w});
    }
    int start = 0, finish = 2;
    cout << bfa(start, finish, n, edges);
}