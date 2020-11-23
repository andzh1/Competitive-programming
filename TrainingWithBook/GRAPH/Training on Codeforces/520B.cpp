#include <bits/stdc++.h>
using namespace std; 
//https://codeforces.com/problemset/problem/520/B



int main(){
    int n, m;
    cin >> n >> m;
    if(n >= m) cout << n-m << '\n';
    else
    {
        int counter = 0;
        while(m > n){
            if(m % 2 == 1)
            {
                counter ++;
                m++;
            } 
            m /= 2;
            counter ++;
        }
        counter += n-m;
        cout << counter << '\n';
    }
}
