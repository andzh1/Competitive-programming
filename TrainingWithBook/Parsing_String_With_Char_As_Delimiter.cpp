#include <bits/stdc++.h> 
using namespace std; 

int main() 
{ 
	string line = "Lol=does=it=work"; 
	vector <string> tokens; 
	stringstream input(line); 
	
	string currentInput; 
	char delimiter = '=';
	while(getline(input, currentInput, delimiter)) 
	{ 
		tokens.push_back(currentInput); 
	} 
	for(auto cur: tokens) cout << cur << '\n';
} 



