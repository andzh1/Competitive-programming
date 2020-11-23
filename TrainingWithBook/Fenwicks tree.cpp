#include <bits/stdc++.h>
using namespace std; 

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

int maxPowerOf2(int k){
    return k & -k;
}

vector <int> getFenwicksTree(int n, int input[]){
    vector <int> fenwicksTree;
    vector <int> prefixSumms = getPrefixSumms(n, input);
    for(int i = 1; i <= n; i++){
        fenwicksTree.push_back(summ(i - maxPowerOf2(i), i-1, prefixSumms));
    }
    return fenwicksTree;
}

int summInFenwicksTree(int k, vector <int> fenwicksTree) //returns summ in range of 1 to k of input[]
{
    int summ = 0;
    while(k >= 1){
        summ += fenwicksTree[k-1];
        k -= maxPowerOf2(k);
    }
    return summ;
}

vector <int> changeElementInFenwicksTree(vector <int> fenwicksTree, int ip, int dif) //how will change fenwicksTree, if we will add to input[ip] dif (dif could be < 0)
{
    vector <int> newFenwicksTree = fenwicksTree;
    int n = fenwicksTree.size();
    while(ip <= n) {
        newFenwicksTree[ip-1] += dif;
        ip += maxPowerOf2(ip);
    }
    return newFenwicksTree;
} 

int main(){
    int n;
    cin >> n;
    int input[n];
    for(int i = 0; i < n; i++) cin >> input[i];
    vector <int> fenwicksTree = getFenwicksTree(n, input);
    for(auto x: fenwicksTree) cout << x << " ";
    cout << '\n';
    fenwicksTree = changeElementInFenwicksTree(fenwicksTree, 4, 100);
    for(auto x: fenwicksTree) cout << x << " ";
}
