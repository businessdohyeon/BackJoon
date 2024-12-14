/*
BackJoon No.
#32288
*/

#include <iostream>
#include <string>

using namespace std;

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	string str;
	cin >> str;

	for(int i=0; i<str.length(); ++i){
		if(str[i] == 'l'){
			str[i] = 'L';
		}else if(str[i] == 'I'){
			str[i] = 'i';
		}else{
			// do nothin'
		}
	}

	cout << str;

	return 0;
}