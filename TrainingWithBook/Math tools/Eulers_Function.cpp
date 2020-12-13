#include <bits/stdc++.h>
using namespace std; 

long long EulersFunction(long long n) //Returns amount of numbers x from 1 to n and gcd(x, n) = 1
{
    long long result = n;
    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}

int main(){
    cout << EulersFunction(10);
}
