#include <bits/stdc++.h>
using namespace std; 
//we want to count minimal distance between 2 strings from n given; all given strings have the same length

int slowHamming(string a, string b){
    int dist = 0;
    for(int i = 0; i < a.length(); i++){
        dist += (a[i] != b[i]);
    }
    return dist;
}
//our strings are actually bitsets, so we can convert them to integer

int fastHamming(int a, int b){
    return __builtin_popcount(a^b);
}
//a^b - if a[i] == b[i], a^b[i] = 1, and vice versa
int main(){
    
}