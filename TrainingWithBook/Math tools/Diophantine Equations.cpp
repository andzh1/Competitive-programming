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
/* Description
Returns such pair {x, y} that exists to a*x + b*y = c (a,b,c,x,y - integer numbers).
Diophantine equation has a solution only if c % gcd(a, b) == 0, unless there is no solution in integer numbers.
In this function, we don't check whether c % gcd(a, b) == 0, but we suppose that we've already checked it.*/
pair <intType, intType> solutionOfDiophantineEquation(intType a, intType b, intType c) 
{
    intType x, y, g;
    tie(x, y, g) = modernGCD(a, b);
    intType difference = c/__gcd(a, b);
    return {x*difference, y*difference};
}

int main(){
    pair <intType, intType> answer = solutionOfDiophantineEquation(39, 15, 12);
    cout << answer.first << " " << answer.second;
}
