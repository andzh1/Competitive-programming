#include <bits/stdc++.h>
using namespace std; 
//https://codeforces.com/problemset/problem/1327/B

int main(){
    int TT;
    cin >> TT;
    for(int UU = 0; UU < TT; UU++){
        int n;
        cin >> n;
        vector <int> daughterPreferences[n];
        for(int i = 0; i < n; i++){
            int k;
            cin >> k;
            for(int j = 0; j < k; j++){
                int x;
                cin >> x;
                daughterPreferences[i].push_back(x-1);
            }
        }
        bool princesses[n], princes[n];
        for(int i = 0; i < n; i++){
            princesses[i] = false;
            princes[i] = false;
        }
        int amount = 0;
        for(int i = 0; i < n; i++){
            if(daughterPreferences[i].size() != 0) {
                for(auto x: daughterPreferences[i]){
                    if(!princes[x]) {
                        princesses[i] = true;
                        princes[x] = true;
                        amount++;
                        break;
                    }
                }
            }
        }
        if(amount == n) cout << "OPTIMAL\n";
        else
        {
            int ip1, ip2;
            for(int i = n - 1; i >= 0; i--){
                if(!princesses[i]) ip1 = i + 1;
                if(!princes[i]) ip2 = i + 1;
            }
            cout << "IMPROVE\n" << ip1 << " " << ip2 << '\n';
        }
        
    }
}
