#include <bits/stdc++.h>
using namespace std; 
//returns summ of subarray between given pointers a & b

int summ(int a, int b, vector <int> prefixSumms){
    if(a == 0) return prefixSumms[b];
    return prefixSumms[b] - prefixSumms[a-1];
}

vector <int> getPrefixSumms(int n, int input[]){
    vector <int> prefixSumms;
    prefixSumms.push_back(input[0]);
    for(int i = 1; i < n; i++) {
        int x = prefixSumms.back() + input[i];
        prefixSumms.push_back(x);
    }
    return prefixSumms;
}

int main(){
    int n;
    cin >> n;
    int input[n];
    for(int i = 0; i < n; i++) cin >> input[i];    
    vector <int> prefixSumms = getPrefixSumms(n, input);
    int a, b;
    cin >> a >> b;
    cout << summ(a-1,b-1, prefixSumms);
}
