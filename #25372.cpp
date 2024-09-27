/*
BackJoon No.
#25372
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

		cout << (str.length() >= 6 && str.length() <= 9 ? "yes" : "no") << '\n';
	}

	return 0;
}