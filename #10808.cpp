/*
BackJoon No.
#10808
*/

#include <iostream>
#include <string>

using namespace std;

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	string str;
	cin >> str;

	int ans['z'-'a'+1] = {0, };
	for(char ch : str){
		++ans[ch - 'a'];
	}

	for(int val : ans){
		cout << val << ' ';
	}

	return 0;
}