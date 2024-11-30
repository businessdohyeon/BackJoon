/*
BackJoon No.
#32154
*/

#include <iostream>
#include <string>

using namespace std;

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	string s[10] = {"ABCDEFGHJLM", 
					"ACEFGHILM", 
					"ACEFGHILM", 
					"ABCEFGHLM", 
					"ACEFGHLM", 
					"ACEFGHLM", 
					"ACEFGHLM", 
					"ACEFGHLM", 
					"ACEFGHLM", 
					"ABCFGHLM"};

	int n;
	cin >> n;

	string& str = s[n-1];
	cout << str.length() << '\n';
	for(char ch : str){
		cout << ch << ' ';
	}

	return 0;
}