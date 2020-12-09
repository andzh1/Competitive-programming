#include <bits/stdc++.h>
using namespace std;

bool cost(string s1, int p1, string s2, int p2){
    return s1[p1] != s2[p2];
}

int min3(int input1, int input2, int input3){
    return min(min(input1, input2), input3);
}

int costOfEdit(string s1, int p1, string s2, int p2, vector <int> costs[]){
    if(p1 < 0) {
        return p2 - p1;
    }
    else if(p2 < 0) {
        return p1 - p2;
    }
    else if(costs[p1][p2] > -1) return costs[p1][p2];
    else 
    {
        int cost1 = costOfEdit(s1, p1, s2, p2 - 1, costs) + 1;
        int cost2 = costOfEdit(s1, p1 - 1, s2, p2, costs) + 1;
        int cost3 = costOfEdit(s1, p1 - 1, s2, p2 - 1, costs) + cost(s1, p1, s2, p2);
        costs[p1][p2] = min3(cost1, cost2, cost3);
    }
    return costs[p1][p2];
}

int main(){
    string s1, s2;
    cin >> s1 >> s2;
    if(s1.size() < s2.size()) swap(s1, s2);
    int p1 = s1.size(), p2 = s2.size();
    vector <int> costs[p1];
    for(int i = 0; i < p1; i++){
        for(int j = 0; j < p2; j++) costs[i].push_back(-1);
    }
    int answer = costOfEdit(s1, p1 - 1, s2, p2 - 1, costs);
    cout << answer;
}


