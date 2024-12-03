/*
BackJoon No.
#11365
*/

#include <iostream>
#include <string>

using namespace std;

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	while(true){
		string str;
		getline(cin, str);

		if(str == "END")		break;

		for(auto p=str.rbegin(); p != str.rend(); ++p){
			cout << *p;
		}

		cout << '\n';
	}
	

	return 0;
}