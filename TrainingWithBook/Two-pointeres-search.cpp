#include <bits/stdc++.h>
using namespace std; 
//our goal is to find in array of integers sequence of elements, which summ if x

int main(){
    int n, x;
    cin >> n >> x;
    int input[n];
    for(int i = 0; i < n; i++) cin >> input[i];
    int a = 0, b = 0, summ = input[0];
    bool containsSeq = false;
    int first, second;
    while(b < n && !containsSeq){
        if(summ == x) {
            containsSeq = true; 
            first = a;
            second = b;
        }
        if(summ > x){
            a ++;
            summ -= input[a-1];
            if(a > b) b++;
        }
        if(summ < x && b < n-1) {
            b++;
            summ += input[b];
        }
        if(summ < x && b == n-1) {
            containsSeq = false;
        }
        if(a == b && b == n-1) break;
    }
    if(containsSeq) cout << "yes " << first << " " << second;
    else cout << "no";
}