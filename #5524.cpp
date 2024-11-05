/*
BackJoon No.
#5524
*/

#include <iostream>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	for(int i=0; i<n; ++i){
		string str;
		cin >> str;

		for(int j=0; j<str.length(); ++j){
			if(str[j] >= 'A' && str[j] <= 'Z'){
				str[j] = str[j] - 'A' + 'a';
			}
		}
		cout << str << '\n';
	}

	return 0;
}