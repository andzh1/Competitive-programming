#include <bits/stdc++.h>
using namespace std;

vector <int> getPathArray(int startingVertex, int previousVertex, vector <int> tree[]){
    vector <int> answer;
    answer.push_back(startingVertex);
    for(auto nextVertex: tree[startingVertex]){
        vector <int> currentPathArray;
        if(nextVertex != previousVertex){
            currentPathArray = getPathArray(nextVertex, startingVertex, tree);
            for(auto x:currentPathArray) answer.push_back(x);
        }
    }
    return answer;
}

int main(){
    int amountOfVertices;
    cin >> amountOfVertices;
    vector <int> tree[amountOfVertices];
    for(int i = 0; i < amountOfVertices - 1; i++) //Amount of edges in every tree is amountOfVertices - 1
    {
        int a, b;
        cin >> a >> b;
        tree[a-1].push_back(b-1);
        tree[b-1].push_back(a-1);   
    } //We initialised a tree
    int startingVertex;
    cin >> startingVertex;
    vector <int> arrayOfPath = getPathArray(startingVertex-1, -1, tree);
}