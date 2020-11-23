#include <bits/stdc++.h>
using namespace std; 
#define loop(a,b) for(int i = a; i < b; i++)


int main(){
    int n = 5, wanted = 5;
    int array[] = {1,2,3,4,5};
    int a = 0, b = n - 1;
    while(a <= b) {
        int k = (a+b)/2;
        if(array[k] == wanted) {
            //we got wanted value
        }
        if(array[k] < wanted) a = k + 1;
        else b = k - 1;
    }

}
