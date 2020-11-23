#include <bits/stdc++.h>
using namespace std; 
#define loop(a,b) for(int i = a; i < b; i++)


int main(){
    int m = 12;//summ of all weights
    int n = 4;//amount of weights
    int w[] = {1,3,3,5};//all weights
    
    bool possible[m + 1];
    for(int i = 1; i <= m; i++) possible[i] = false;
    possible[0] = true;


    for(int k = 0; k < n; k++) {
        for(int x = m - w[k]; x >= 0; x-- ){
            possible[x+w[k]] |= possible[x];
        }
    }
    
        for(int j = 0; j <= m; j++) cout << possible[j] << " ";
        cout << '\n';
    
}
