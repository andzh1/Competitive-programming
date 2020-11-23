#include <bits/stdc++.h>
using namespace std; 



int main(){
    int n = 777;
    vector <int> adj1[n]; //array of "adjacencies" - edges of our graph
    adj1[1].push_back(2);
    adj1[2].push_back(3);
    adj1[2].push_back(4);
    /*Ориентированный граф - то же самое, но надо определить, какая вершина - начало ребра, а какая - конец*/
    /*Взвешенный граф:*/
    vector <pair<int,int>> adj2[n]; //adj[i] - {x,y}, x - # of vertex, y - weight of edge i,x
    adj2[2].push_back({4,4});// in our graph we can find edge (2;4) with weight 4
    int s;//в цикле обходим все ребра, которые выходят из вершины с номером s
    for(auto u: adj[s]){
        //обрабатываем 
    }

    /*МАТРИЦА СМЕЖНОСТИ*/
    int matrixOfAdj[n][n];
    //If in our graph we can find an edge (i;j), matrixOfAdj[i][j] will be equal to the weight of that edge & if there is no edge (i;j), matrixOfAdj[i][j] = 0

    /*LIST OF ALL EDGES*/
    vector <pair<int,int>> edges;
    //if there is an edge (i;j), we add it as a pair of vertexes to our list
    //if edges in our graph have a weight, we can extend our list:
    vector <tuple<int,int,int>> edges1;//{i,j,weight}







}
