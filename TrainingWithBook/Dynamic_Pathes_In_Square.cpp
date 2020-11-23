#include <bits/stdc++.h>
using namespace std; 
#define loop(a,b) for(int i = a; i < b; i++)
const int edge = 6;
// int findPath(int )

int main(){
    int square[edge][edge];
    int pathes[edge][edge];
    for(int i = 0; i < edge; i++) for(int j = edge - 1; j >= 0; j--) {cin >> square[i][j]; pathes[i][j] = 0;}
    pathes[0][0] = 0;
    for(int i = 1; i < edge; i++) {pathes[0][i] = square[0][i - 1] + pathes[0][i-1]; pathes[i][0] = square[i-1][0] + pathes[i-1][0];}
    for(int i = 1; i < edge; i++){
        for(int j = 1; j < edge; j++) pathes[i][j] = max(pathes[i][j-1] + square[i][j-1], pathes[i-1][j] + square[i-1][j]);
    }
    cout << pathes[edge - 1][edge - 1] + square[edge - 1][edge - 1];
}
