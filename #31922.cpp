/*
BackJoon No.
#31922
*/

#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int a, p, c;
	cin >> a >> p >> c;
	cout << max(a+c, p);

	return 0;
}