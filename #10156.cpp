/*
BackJoon No.
#10156
*/

#include <iostream>

using namespace std;

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int k, m, n;
	cin >> k >> m >> n;

	cout << (k*m-n > 0 ? k*m-n : 0);

	return 0;
}