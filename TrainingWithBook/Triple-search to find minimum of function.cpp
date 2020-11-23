#include <bits/stdc++.h>
using namespace std;

const int setpressor = 5;

double f(double x){
    return x*x + 78;
}

double findMin(double f(double), double left, double right){
    if(right - left <= 0.0001) return (right+left)/2;
    double a = (2*left + right)/3;
    double b = (left + 2*right)/3;
    if(f(a) < f(b)) findMin(f, left, b);
    else findMin(f, a, right);
}

int main(){
    cout << setprecision(4);
    cout << findMin(f, -100, 100);
    // cout << 10^(-setpressor);
}