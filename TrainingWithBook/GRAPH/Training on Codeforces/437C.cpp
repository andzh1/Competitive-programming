#include <bits/stdc++.h>
using namespace std; 
//https://codeforces.com/problemset/problem/520/B



int main(){
    int n, m;
    cin >> n >> m;
    int energy[n];
    for(int i = 0; i < n; i++) cin >> energy[i];
    vector <int> adj[n];
    int a, b;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }
    int summaryEnergies[n];
    int minimum = INT32_MAX, ipMin;
    bool notBreaken[n];
    for(int i = 0; i < n; i++ ) notBreaken[i] = true;
    for(int i = 0; i < n; i++){
        summaryEnergies[i] = 0;
        for(auto x: adj[i]) summaryEnergies[i] += energy[x];
        if(minimum > summaryEnergies[i]){
            minimum = summaryEnergies[i];
            ipMin = i;
        }
    }
    int answer = 0;
    for(int j = 0; j < n; j++) {
        answer += minimum;
        notBreaken[ipMin] = false;
        for(auto x: adj[ipMin]) summaryEnergies[x] -= energy[ipMin];
        minimum = INT32_MAX;
        for(int i = 0; i < n; i++){
            if(minimum > summaryEnergies[i] && notBreaken[i]){
                minimum = summaryEnergies[i];
                ipMin = i;
            }
            else if(minimum == summaryEnergies[i] && notBreaken[i] && energy[i]*adj[i].size() > energy[ipMin]*adj[ipMin].size()){
                minimum = summaryEnergies[i];
                ipMin = i;
            }
        }
    }
    cout << answer << '\n';
}
