#include <bits/stdc++.h>
using namespace std; 

void getTreeOfSegments(int treeOfSegments[], int input[], int n){
    for(int i = n; i < 2*n; i++) treeOfSegments[i] = input[i-n];
    for(int i = n - 1; i >= 0; i--) treeOfSegments[i] = treeOfSegments[2*i] + treeOfSegments[2*i + 1];
}

int summ(int a, int b, int n, int treeOfSegments[]){
    a += n; b += n;
    int summ = 0;
    while(a <= b){
        if(a % 2 == 1) summ += treeOfSegments[a++];
        if(b % 2 == 0) summ += treeOfSegments[b--];
        a /= 2;
        b /= 2;
    }
    return summ;
}

void changeElementInTreeOfSegments(int ip, int dif, int n, int treeOfSegments[])
{
    ip += n; 
    treeOfSegments[ip] += dif;
    for(ip /= 2; ip >= 1; ip /= 2){
        treeOfSegments[ip] = treeOfSegments[2*ip] + treeOfSegments[2*ip + 1];
    }
}

int main(){
    int n;
    cin >> n;
    int input[n];
    for(int i = 0; i < n; i++) cin >> input[i];
    int treeOfSegments[2*n];
    getTreeOfSegments(treeOfSegments, input, n);
    changeElementInTreeOfSegments(0, 100, n, treeOfSegments);
    for(int i = 1; i < 2*n; i++) cout << treeOfSegments[i] << " ";
    // cout << summ(0, 7, n, treeOfSegments);

}
