/*
BackJoon No.
#15727
*/

#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;
	cout << (n % 5 == 0 ? n/5 : n/5 + 1);

	return 0;
}