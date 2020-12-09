#include <bits/stdc++.h>
using namespace std;

const int A = 3, B = 97; /* We "convert" our string in a number like that: 
X = A^n*s[0] + A^(n-1)*s[1] + ... + s[n-1], n = s.length(), s - our string. 
Because X will be too big for int (even for long long int) if n >= 10,
we save X just as X % B. By the way, if n < 33 we can use B = 1 to get not X % B, but X as an answer.*/

vector <int> getPowersOfA(int lengthOfString){
    vector <int> pow;
    pow.push_back(1);
    for(int i = 1; i < lengthOfString; i++){
        pow[i] = (pow[i-1]*A) % B;
    }
    return pow; //pow[i] = A^i mod B
}

vector <int> getHashcodesOfPrefixes(string input){
    vector <int> hashcodes;
    hashcodes.push_back(input[0] % B);
    for(int i = 1; i < input.length(); i++){
        hashcodes.push_back((hashcodes[i-1]*A + input[i])%B);
    }
    return hashcodes;
}

vector <int> getHashcodesOfSubstrings(string input, vector <pair <int, int>> requests) //each request contains pair (a,b), which means that we have to return hashcode of substring input[a...b].
{
    vector <int> powersOfA = getPowersOfA(input.length());
    vector <int> prefixHashcodes = getHashcodesOfPrefixes(input); 
    vector <int> hashcodes;
    for(auto currentRequest:requests){
        int ipLeft = currentRequest.first, ipRight = currentRequest.second;
        if(ipLeft == 0) hashcodes.push_back(prefixHashcodes[ipRight]);
        else {
            hashcodes.push_back((((prefixHashcodes[ipRight] - prefixHashcodes[ipLeft - 1]*powersOfA[(ipRight - ipLeft + 1)])% B) + B)%B);
        }
    }
    return hashcodes;
}

int main(){
    string s;
    cin >> s;
    vector <pair <int, int>> requests;
    requests.push_back({0,1});
    requests.push_back({1,2});
    requests.push_back({3,4});
    requests.push_back({2,3});
    vector <int> answers = getHashcodesOfSubstrings(s, requests);
    for(int i = 0; i < answers.size(); i++){
        cout << "Hashcode of substring (" << requests[i].first << ", " << requests[i].second << ") is " << answers[i] << '\n';
    }

}


