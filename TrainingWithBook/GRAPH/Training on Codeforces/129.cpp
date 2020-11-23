#include <bits/stdc++.h>
using namespace std; 
//https://codeforces.com/problemset/problem/1428/B



int main(){
    int TT;
    cin >> TT;
    for(int UU = 0; UU < TT; UU++){
        int n;
        cin >> n;
        string input;
        cin >> input;
        int amountOfRightOriented = 0, amountOfLeftOriented = 0;
        vector <int> ipOfTurnedOffConvectors;
        for(int i = 0; i < n; i++){
            switch (input[i])
            {
            case '-':
                ipOfTurnedOffConvectors.push_back(i);
                break;
            case '>':
                amountOfRightOriented ++;
                break;
            case '<':
                amountOfLeftOriented ++;
                break;
            }
        }
        if(!amountOfRightOriented || !amountOfLeftOriented) cout << n;
        else 
        {
            bool returnable[n];
            for(int i = 0; i < n; i++){
                returnable[i] = false;
            }
            for(auto x: ipOfTurnedOffConvectors){
                returnable[x] = true;
                if(x < n - 1) returnable[x+1] = true;
                else returnable[0] = true;
            }
            int amount = 0;
            for(int i = 0; i < n; i++) if(returnable[i]) amount++;
            cout << amount;
        }
        cout << '\n';
    }
}
