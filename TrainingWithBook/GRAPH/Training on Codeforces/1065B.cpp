#include <bits/stdc++.h>
using namespace std; 
//https://codeforces.com/problemset/problem/1065/B


int main(){
    long long n, m;
    cin >> n >> m;
    if(n < 2*m) cout << "0 ";
    else cout << n - 2*m << " ";
    long long ans;
    for(long long i = sqrt(m); i <= n; i++){
        ans = i*(i-1)/2;
        if(ans >= m) {
            cout << n-i << '\n';
            break;
        }
    }

}
