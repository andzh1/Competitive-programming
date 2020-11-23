#include <bits/stdc++.h>
using namespace std;

int getSummOfSubtree(int root, int parentOfRoot, vector <int> tree[], int values[]) //We have to count summ of values in all vertices of subtree with root "root". In vertex i values[i] is located 
{
    int summ = values[root];
    for(auto nextVertex: tree[root]){
        if(nextVertex != parentOfRoot) summ += getSummOfSubtree(nextVertex, root, tree, values);
    }
    return summ;
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
    int startingRoot;
    cin >> startingRoot;
    int values[amountOfVertices];
    for(int i = 0; i < amountOfVertices; i++) cin >> values[i];
    cout << getSummOfSubtree(3, 0, tree, values); //We have to find parent for our startingRoot. We can do it in O(n) - we need to do dfs & vertex i will be a parent for all j:tree[i], j != parent(i). 
}