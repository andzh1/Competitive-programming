#include <bits/stdc++.h>
using namespace std; 
//https://codeforces.com/problemset/problem/1255/B

int main(){
    int TT;
    cin >> TT;
    for(int UU = 0; UU < TT; UU++){
        int n, m, summ = 0;
        cin >> n >> m;
        int input[n], kaput[n];
        for(int i = 0; i < n; i++) {
            cin >> input[i];
            summ += input[i];
            kaput[i] = input[i];
        }
        sort(kaput, kaput + n);
        int ip1, ip2, min1 = kaput[0], min2 = kaput[1];
        for(int i = 0; i < n; i++) if(input[i] == min1) ip1 = i;
        input[ip1] = -1;
        for(int i = 0; i < n; i++) if(input[i] == min2) ip2 = i;
        if(n > m || n == 2) cout << "-1\n";
        else {
            summ += (m-n)*(input[ip1] + input[ip2]);
            cout << 2*summ << '\n';
            for(int i = 1; i < n; i++){
                cout << i << " " << i+1 << '\n';
            } 
            cout << n << " 1\n";
            for(int i = 0; i < (m - n); i++) cout << ip1 + 1 << " " << ip2 + 1 << '\n';
        } 
    }
}
