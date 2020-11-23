#include <bits/stdc++.h>
using namespace std; 
//https://codeforces.com/problemset/problem/948/A

int main(){
    int r, c;
    cin >> r >> c;
    string field[r];
    for(int i = 0; i < r; i++) cin >> field[i];
    bool isPossible = true;
    for(int i = 0; i < r && isPossible; i++){
        for(int j = 0; j < c && isPossible; j++){
            switch (field[i][j])
            {
            case 'S':
                if(j < c - 1 && field[i][j+1] == 'W') isPossible = false;
                if(j > 0 && field[i][j-1] == 'W') isPossible = false;
                if(i < r - 1 && field[i+1][j] == 'W') isPossible = false;
                if(i > 0 && field[i-1][j] == 'W') isPossible = false;
                break;
            case '.':
                field[i][j] = 'D';
                break;
            default:
                break;
            }
        }
    }
    if(isPossible){
        cout << "YES\n";
        for(int i = 0; i < r; i++) cout << field[i] << '\n';
    } else cout << "NO\n";
}
