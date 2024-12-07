/*
BackJoon No.
#23825
*/

#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int a, b;
	cin >> a >> b;
	cout << min(a/2, b/2);

	return 0;
}