/*
BackJoon No.
#2744
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

	for(auto itr = str.begin(); itr != str.end(); ++itr){
		if(*itr >= 'a' && *itr <= 'z'){
			*itr = *itr - 'a' + 'A';
		}else{
			*itr = *itr - 'A' + 'a';
		}
	}
	cout << str;

	return 0;
}