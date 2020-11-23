#include <bits/stdc++.h>
using namespace std; 
#define loop(a,b) for(int i = a; i < b; i++)


int main(){
    int n = 5;
    n++;
    int value[n][n];
    int sum[n][n];
    n--;
    for(int i = 0; i <= n; i++){
        sum[0][i] = 0;
        sum[i][0] = 0;
    }
    for(int y = 1; y <= n; y++){
        for(int x = 1; x <= n; x++) {
            sum[y][x] = max(sum[y][x-1], sum[y-1][x]) + value[y][x];
        }
    }
}
