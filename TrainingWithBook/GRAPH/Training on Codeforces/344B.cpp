#include <bits/stdc++.h>
using namespace std; 
//https://codeforces.com/problemset/problem/344/B


int main(){
    int a,b,c;
    cin >> a >> b >> c;
    if((a+b+c) % 2 != 0) cout << "Impossible\n";
    else
    {
        int ab = (a + b - c)/2;
        int bc = (b + c - a)/2;
        int ca = (c + a - b)/2;
        if(ab < 0 || bc < 0 || ca < 0) cout << "Impossible\n";
        else {
            if(a+b+c == ab || a+b+c == bc || a+b+c == ca) cout << "Impossible\n";
            else cout << ab << " "<< bc << " "<< ca;
        }
    }
    
}
