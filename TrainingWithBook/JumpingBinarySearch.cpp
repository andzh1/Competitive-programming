#include <bits/stdc++.h>
using namespace std; 
#define loop(a,b) for(int i = a; i < b; i++)


int main(){
    int n = 5, wanted = 5;
    int array[] = {1,2,3,4,5};
    int k = 0;
    for(int b = n/2; b >= 1; b /= 2){
        while(k + b < n && array[k+b] <= wanted) k += b;
    }
    if(array[k] == wanted){
        //we got wanted value
    } 
}
