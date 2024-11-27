/*
BackJoon No.
#25191
*/

#include <iostream>

using namespace std;

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int n, a, b;
	cin >> n >> a >> b;

	cout << min(n, a/2 + b);

	return 0;
}