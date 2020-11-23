#include <bits/stdc++.h>
using namespace std; 
//https://codeforces.com/problemset/problem/522/A

int breadthFirstSearch(map <string, vector<string>> adj, map <string, bool> visited, map <string, int> distances, queue <string> queueOfVertexes){
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
    return ch >= '0' && ch <= '9';
}

string toLower(string input){
    string answer = "";
    for(int i = 0; i < input.length(); i++){
        if(isDigit(input[i]) || input[i] >= 'a') 
            answer += input[i];
        else
            answer += input[i] - ('Z' - 'z');
    }
    return answer;
}


int main(){
    int n;
    cin >> n;
    map <string, vector<string>> adj;
    map <string, bool> visited;
    map <string, int> distances;
    for(int i = 0; i < n; i++){
        string  to, ignore, from;
        cin >> to >> ignore >> from;
        from = toLower(from);
        to = toLower(to);
        adj[from].push_back(to);
        visited[to] = false;
    }
    string root = "polycarp";
    distances[root] = 1;
    visited[root] = true;
    queue <string> queueOfVertexes;
    queueOfVertexes.push(root);
    
    cout << breadthFirstSearch(adj, visited, distances, queueOfVertexes);
    
}
