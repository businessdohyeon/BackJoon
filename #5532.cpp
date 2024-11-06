/*
BackJoon No.
#5532
*/

#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	double l, a, b, c, d;
	cin >> l >> a >> b >> c >> d;

	cout << l - max(ceil(a/c), ceil(b/d));

	return 0;
}