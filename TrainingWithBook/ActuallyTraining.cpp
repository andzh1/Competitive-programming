#include <bits/stdc++.h>
using namespace std; 



int main(){
     int n;
     cin >> n;
     int input[n];
     for(int i = 0; i < n; i++) cin >> input[i];
     for(int i = 0; i < n; i++){
         int x = input[(3*i)%n]^input[(3*i+3)%n]^input[(3*i+6)%n];
         input[(3*i)%n] = x;
         input[((3*i)+2)%n] = x;
         input[((3*i)+4)%n] = x;
     }
     for(int i = 0; i < n; i++) cout << input[i] << " ";
}
