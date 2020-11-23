#include <bits/stdc++.h>
using namespace std; 
//https://codeforces.com/problemset/problem/1033/A

int main(){
    int n;
    cin >> n;
    int Ax, Ay, Bx, By, Cx, Cy;
    cin >> Ax >> Ay >> Bx >> By >> Cx >> Cy;
    if(((Ax > Bx && Ax > Cx) || (Ax < Bx && Ax < Cx)) 
        && ((Ay > By && Ay > Cy) || (Ay < By && Ay < Cy))) cout << "YES";
    else cout << "NO";
     
}
