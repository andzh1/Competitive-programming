#include <bits/stdc++.h>
using namespace std; 

long long EulersFunction(long long n) // Returns amount of numbers x from 1 to n and gcd(x, n) = 1
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

typedef int intType; //mb long int or long long required

intType modpow(intType x, intType power, intType module) // Returns (x^power) % module
{
    if(power == 0) return 1%module;
    if(power % 2 == 0) return modpow(x, power/2, module)*modpow(x, power/2, module)%module;
    if(power % 2 == 1) return x * modpow(x, power - 1, module) % module;
}

intType inverceNumber(intType inputNumber, intType module) // Returns X that X * inputNumber % module = 1
{
    return modpow(inputNumber, EulersFunction(module) - 1, module);
}

long long ChineseRemainerTheorem(vector <pair <intType, intType>> equations){
    long long answer = 0;
    long long X = 1;
    for(auto eq: equations) {
        while(eq.first > eq.second) eq.first -= eq.second;
    }
    for(auto eq: equations) X *= eq.second;
    for(auto eq: equations) answer += eq.first * (X/eq.second) * inverceNumber(X/eq.second, eq.second);
    return answer;
}

int main(){
    vector <pair <intType, intType>> equations;
    equations.push_back({3, 5});
    equations.push_back({4, 7});
    equations.push_back({2, 3});
    cout << ChineseRemainerTheorem(equations);
}
