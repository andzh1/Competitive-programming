#include <bits/stdc++.h>
using namespace std; 
//https://codeforces.com/problemset/problem/94/B

const int loopLength = 3;


int main(){
    int m;
    cin >> m;
    bool friends[5][5];
    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 5; j++)
            friends[i][j] = false;
    int a, b;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        friends[a-1][b-1] = true;
        friends[b-1][a-1] = true;
    }
    bool containsTriangle = false;
    for(int i = 0; i < 3; i++){
        for(int j = i+1; j < 4; j++){
            for(int k = j+1; k < 5; k++){
                if((friends[i][j] && friends[j][k] && friends[k][i]) || (!friends[i][j] && !friends[j][k] && !friends[i][k])) {
                    containsTriangle = true;
                    break;
                }
            }
        }
    }
    if(containsTriangle) cout << "WIN\n";
    else cout << "FAIL\n";
    

}
