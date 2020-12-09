#include <bits/stdc++.h>
using namespace std;

/* Description 
Our goal is to build for string s array Z[n] (n = s.length()),
where Z[i] - max possible length of substring s[i..i+p-1], which is 
prefix of s (in other words, s[i..i+p-1] == s[0..p-1], p -> max) */
vector <int> getZ_array(string input)
{
    vector <int> Z;
    Z.push_back(input.length());
    int ipLeft = 0, ipRight = 0; 
    for(int ip = 1; ip < input.size(); ip++){
        char ch = input[ip];
        if(ipRight < ip){
            int counter = 0;
            while(input[counter] == input[counter + ip] && counter + ip < input.length()) counter ++;
            Z.push_back(counter);
            if(counter > 0){
                ipLeft = ip;
                ipRight = ip + counter - 1;
            }
        }
        else
        {
            if(ip + Z[ip - ipLeft] <= ipRight) Z.push_back(Z[ip - ipLeft]);
            else
            {
                int counter = 0;
                while(input[ipRight - ipLeft + counter] == input[ipRight + 1 + counter] && (ipRight + 1 + counter < input.length())) { 
                    counter ++;
                }
                ipLeft = ip;
                ipRight += counter;
                Z.push_back(ipRight - ipLeft + 1);
            }
        }
    }
    return Z;
}


/* Description
We want to count, how many times can we find given substring in input (in different positions) */
int countSubstrings(string input, string substring){
    char delimiter = '#'; //delimiter - symbol, which both strings (input & substring) 100% don't contain.
    vector <int> Z = getZ_array(substring + delimiter + input);
    int answer = 0;
    for(auto x: Z) answer += (x == substring.length());
    return answer;
}
/* Example:
input = abcabc, substring = abc, string-argument for getZ_array() = abc#abcabc, 
Z = {10, 0, 0, 0, 3, 0, 0, 3, 0, 0}, => answer = 2 */


int main(){
    string s, p;
    cin >> s >> p;
    cout << countSubstrings(s, p);
}


