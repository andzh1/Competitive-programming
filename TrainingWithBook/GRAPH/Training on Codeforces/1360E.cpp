#include <bits/stdc++.h>
using namespace std; 


int main(){
    int TT;
    cin >> TT;
    for(int UU = 0; UU < TT; UU++){
        int n;
        cin >> n;
        string polygon[n];
        for(int i = 0; i < n; i++) cin >> polygon[i];
        bool isPossible = true;
        for(int i = 0; i < n - 1; i++){
            for(int j = 0; j < n - 1; j++)
                if(polygon[i][j] == '1' && polygon[i+1][j] == '0' && polygon[i][j+1] == '0') isPossible = false;
        }
        if(isPossible) cout << "YES\n";
        else cout << "NO\n";
    }
}
