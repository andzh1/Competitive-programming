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
Returns amount of ways how we can split set of n in subsets of Ks[0], Ks[1], ... elements.
Summ of all Ks[i] has to be = n. */
long long multinominalCoefficient(intType n, vector <intType> Ks) 
{
    long long answer = factorial(n);
    for(auto k: Ks) answer /= factorial(k);
    return answer;
}

int main(){}
