#include <bits/stdc++.h>
using namespace std; 
#define loop(a,b) for(int i = a; i < b; i++)


int main(){
    int N = 5;
    int weight[] = {2,3,4,5,9};
    int x = 12;
    pair <int, int> best [1<<N];//best[S] = (rides(S), last(S))
    best[0] = {0,0};
    for(int s = 1; s < (1<<N); s++) {
        best[s] = {N+1, 0};
        for(int p = 0; p < N; p++) {
            if(s & (1<<p)) {
                auto option = best[s^(1<<p)];
                if(option.second + weight[p] <= x){
                    //adding p as a member of current ride
                    if(option.first == 0) option.first = 1;
                    option.second += weight[p];
                }
                else {
                    //making special ride for p
                    option.first ++;
                    option.second = weight[p];
                }
                best[s] = min(best[s], option);
            }
        }
    }
    cout << best[(1<<N) - 1].first;
}
