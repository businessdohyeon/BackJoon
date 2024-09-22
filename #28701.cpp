/*
BackJoon No.
#28701
*/

#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	int a = n*(n+1) / 2;
	int b = a*a;
	int c = b;

	cout << a << '\n';
	cout << b << '\n';
	cout << c << '\n';

	return 0;
}