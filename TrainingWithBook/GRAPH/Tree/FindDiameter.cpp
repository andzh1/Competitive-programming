#include <bits/stdc++.h>
using namespace std;

void dfs(int startingVertex, int previousVertex, vector <int> tree[], int length[]){
    if(previousVertex == -1) length[startingVertex] = 0;
    else length[startingVertex] = length[previousVertex] + 1;
    for(auto nextVertex: tree[startingVertex]){
        if(nextVertex != previousVertex) dfs(nextVertex, startingVertex, tree, length);
    }
}

int getDiameter(int amountOfVertices, vector <int> tree[]){
    int length[amountOfVertices];
    dfs(0, -1, tree, length); // We can choose any other starting vertex, result wouldn't change
    int maxLength = 0, ipMax;
    for(int i = 0; i < amountOfVertices; i++)
        if(length[i] > maxLength){
            maxLength = length[i];
            ipMax = i;
        }
    dfs(ipMax, -1, tree, length);
    int diameter = 0;
    for(int i = 0; i < amountOfVertices; i++) diameter = max(length[i], diameter);
    return diameter;
}


int main(){
    int amountOfVertices;
    cin >> amountOfVertices;
    vector <int> tree[amountOfVertices];
    for(int i = 0; i < amountOfVertices - 1; i++){ //Amount of edges in every tree is amountOfVertices - 1
        int a, b;
        cin >> a >> b;
        tree[a-1].push_back(b-1);
        tree[b-1].push_back(a-1);
    } //We initialised a tree
    int diameter = getDiameter(amountOfVertices, tree);
}