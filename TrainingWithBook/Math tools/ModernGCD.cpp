#include <bits/stdc++.h>
using namespace std; 

typedef int intType;

tuple <intType, intType, intType> modernGCD(intType a, intType b) /* Returns cortege of 3 numbers: x, y, gcd(a, b); x, y - solution of equation ax + by = gcd(a,b) */
{
    if(b == 0) return {1, 0, a};
    else
    {
        intType x, y, gcd;
        tie(x, y, gcd) = modernGCD(b, a%b);
        return {y, x - (a/b)*y, gcd};
    }
}

int main(){
    intType x, y, gcd;
    tie(x, y, gcd) = modernGCD(30, 12);
    cout << x << " " << y << " " << gcd;
}
