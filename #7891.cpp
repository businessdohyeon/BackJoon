/*
BackJoon No.
#7891
*/

#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t;
	cin >> t;

	for(int _=0; _<t; ++_){
		int a, b;
		cin >> a >> b;
		cout << a+b << '\n';
	}

	return 0;
}