#include <bits/stdc++.h>
using namespace std; 
//https://codeforces.com/problemset/problem/755/С

void search4components(int start, vector <int> forest[], int components[], int currentAmountOfComponents){
    if(components[start] > 0) return;
    components[start] = currentAmountOfComponents;
    for(auto x: forest[start])
        search4components(x, forest, components, currentAmountOfComponents);
}

int main(){
    int n;
    cin >> n;
    vector <int> forest[n];
    int currentAmountOfComponents = 1, start = -1, b;
    int components[n];
    for(int i = 0; i < n; i++) {
        cin >> b;
        forest[i].push_back(b-1);
        forest[b-1].push_back(i);
        if(b == i+1){
            components[i] = currentAmountOfComponents;
            currentAmountOfComponents ++;
        }
        else {
            components[i] = 0;
            start = i;
        } 
    }
    
    while(start >= 0){
        search4components(start, forest, components, currentAmountOfComponents);
        start = -1;
        for(int i = 0; i < n; i++){
            if(components[i] == 0) start = i;
        }
        currentAmountOfComponents ++;
    }
    cout << currentAmountOfComponents - 1 << '\n';
}
