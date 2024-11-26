/*
BackJoon No.
#21964
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
	cout << str.substr(str.length() - 5, 5);

	return 0;
}