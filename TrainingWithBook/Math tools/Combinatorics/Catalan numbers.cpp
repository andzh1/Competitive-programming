#include <bits/stdc++.h>
using namespace std; 

typedef int intType;

/* Both functions work only if n < 66, because factorial(66) > INT64_MAX */

long long factorial(intType n){
    return (n == 0) ? 1 : factorial(n - 1) * n;
}

long long binominalCoefficient(intType n, intType k){
    return factorial(n)/factorial(k)/factorial(n-k);
}

/* Description
Returns amount of sequences of length 2*k, which contain k '(' &  k ')' 
and in every prefix of this sequence amount of '(' >= amount of '('.
*/
long long CatalansNumber(intType n) 
{
    return binominalCoefficient(2*n, n)/(n+1);
}

int main(){
    cout << CatalansNumber(3);
}
