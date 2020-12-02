#include <bits/stdc++.h>
using namespace std;

void dfs(int startingVertex, int previousVertex, vector <int> tree[]){
    //Process startingVertex
    for(auto nextVertex : tree[startingVertex]){
        if(nextVertex != previousVertex) dfs(nextVertex, startingVertex, tree);
    }
}
//Example of use

void countingDfs(int startingVertex, int previousVertex, vector <int> tree[], int amounts[]){
    //We want to count amounts; amounts[i] - amount of vertices in sub-tree with root i
    amounts[startingVertex] = 1;
    for(auto nextVertex : tree[startingVertex]){
        if(nextVertex == previousVertex) continue;
        countingDfs(nextVertex, startingVertex, tree, amounts);
        amounts[startingVertex] += amounts[nextVertex];
    }
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
    int startingVertex;
    cin >> startingVertex;
    int amounts[amountOfVertices];
    dfs(startingVertex - 1, -1, tree);
    countingDfs(startingVertex - 1, -1, tree, amounts); 
    //In the beginning of our depth-first searches we use -1 as a previous vertex, because vertex where we begin our dfs has no parent
}