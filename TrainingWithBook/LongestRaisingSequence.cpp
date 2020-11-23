#include <bits/stdc++.h>
using namespace std; 
#define loop(a,b) for(int i = a; i < b; i++)


int main(){
    int n;
    int length[n];
    int array[n];
    for(int k = 0; k < n; k++){
        length[k] = 1;
        for(int i = 0; i < k; i++){
            if(array[i] < array[k])
                length[k] = max(length[k], 1 + length[i]);
        }
    }
}
