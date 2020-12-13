#include <bits/stdc++.h>
using namespace std; 

int modpow(int x, int power, int module) //Returns (x^power) % module
{
    if(power == 0) return 1%module;
    if(power % 2 == 0) return modpow(x, power/2, module)*modpow(x, power/2, module)%module;
    if(power % 2 == 1) return x * modpow(x, power - 1, module) % module;
}

int main(){
    cout << modpow(19, 3, 20);
}
