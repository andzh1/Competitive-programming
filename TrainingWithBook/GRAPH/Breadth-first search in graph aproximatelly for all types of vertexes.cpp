#include <bits/stdc++.h>
using namespace std; 
//https://codeforces.com/problemset/problem/522/A

int bfs(map <string, vector<string>> adj, map <string, bool> visited, map <string, int> distances, queue <string> queueOfVertexes){
    int maxDistance = 0;
    while(!queueOfVertexes.empty()){
        string s = queueOfVertexes.front();
        queueOfVertexes.pop();
        for(auto u: adj[s]){
            if(visited[u]) continue;
            visited[u] = true;
            distances[u] = distances[s] + 1;
            maxDistance = max(distances[u], maxDistance);
            queueOfVertexes.push(u);
        }
    }
    return maxDistance;
}
bool isDigit(char ch){
    if(ch >= '0' && ch <= '9') return true;
    else return false;
}

string changingRegistr(string input){
    string answer = "";
    for(int i = 0; i < input.length(); i++){
        if(isDigit(input[i])) answer += input[i];
        else 
        {
            if(input[i] >= 'a') answer += input[i];
            else answer += input[i] - ('Z' - 'z');
        }
    }
    return answer;
}

int main(){
    int n;
    cin >> n;
    string input;
    map <string, vector<string>> adj;
    map <string, bool> visited;
    map <string, int> distances;
    string s;
    for(int i = 0; i < n; i++){
        cin >> s >> input;
        cin >> input;
        input = changingRegistr(input);
        s = changingRegistr(s);
        adj[input].push_back(s);
        visited[s] = false;
    }
    distances["polycarp"] = 1;
    visited["polycarp"] = true;
    queue <string> queueOfVertexes;
    queueOfVertexes.push("polycarp");
    
    cout << bfs(adj, visited, distances, queueOfVertexes);
    
}
