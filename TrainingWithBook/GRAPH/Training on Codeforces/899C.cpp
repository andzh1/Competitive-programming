#include <bits/stdc++.h>
using namespace std; 
//https://codeforces.com/problemset/problem/899/С


int main(){
    int n;
    cin >> n;
    if(n == 2) cout << "1\n1 1\n";
    else if(n == 3) cout << "0\n1 3\n";
    else 
    {
        int rest = n%4;
        switch (rest)
        {
        case 0:
            cout << "0\n" << n/2;
            for(int i = 1; i <= n/4; i++) cout << " " << i;
            for(int i = 3*n/4 + 1; i <= n; i++) cout << " " << i;
            break;
        case 1:
            cout << "1\n" << n/2;
            for(int i = 1; i <= (n-1)/4; i++) cout << " " << i+1;
            for(int i = 3*(n-1)/4 + 1; i <= (n-1); i++) cout << " " << i+1;
            break;
        case 2:
            cout << "1\n" << n/2;
            for(int i = 1; i <= n/4; i++) cout << " " << i;
            for(int i = 3*n/4 + 2; i <= n; i++) cout << " " << i;
            cout << " " << n/2;
            break;
        case 3:
            cout << "0\n" << n/2 << " 3 ";
            for(int i = 1; i <= (n-3)/4; i++) cout << i+3 << " ";
            for(int i = 3*(n-3)/4 + 1; i <= (n-3); i++) cout << i+3 << " ";
            break;
        }
    }
}
