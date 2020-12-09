#include <bits/stdc++.h>
using namespace std;

int lcs(int p1, string s1, int p2, string s2, vector <int> counts[], set <pair<int, int>> undonePairs){
    if(p1 < 0 || p2 < 0) return 0;
    if(undonePairs.find({p1, p2}) == undonePairs.end()) return counts[p1][p2];
    undonePairs.erase({p1, p2});
    if(s1[p1] == s2[p2]) counts[p1][p2] = 1 + lcs(p1-1, s1, p2-1, s2, counts, undonePairs);
    else counts[p1][p2] = max(lcs(p1-1, s1, p2, s2, counts, undonePairs), lcs(p1, s1, p2-1, s2, counts, undonePairs));
    return counts[p1][p2];
}

int main(){
    string s1, s2;
    cin >> s1 >> s2;
    set <pair<int, int>> undonePairs;
    if(s1.length() < s2.length()) swap(s1, s2);
    int p1 = s1.length(), p2 = s2.length();
    vector <int> counts[p1];
    for(int i = 0; i < p1; i++){
        for(int j = 0; j < p2; j++) {
            counts[i].push_back(-1);
            undonePairs.insert({i, j});
        }
    }
    while(undonePairs.size() > 0){
        for(auto x: undonePairs){
            int p1 = x.first, p2 = x.second;
            int q = lcs(p1, s1, p2, s2, counts, undonePairs);
            undonePairs.erase({p1, p2});
            break;
        }
    }
    cout << "  ";
    for(int i = 0; i < s2.size(); i++){
        cout << s2[i] << " ";
    }
    cout << '\n';
    for(int i = 0; i < s1.size(); i++){
        cout << s1[i] << " ";
        for(auto x : counts[i]) cout << x << " ";
        cout << '\n';
    }
}


