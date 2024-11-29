/*
BackJoon No.
#25238
*/

#include <iostream>

using namespace std;

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	double a, b;
	cin >> a >> b;
	double per = (100-b) / 100;
	int ans = (a * per < 100);
	cout << ans;

	return 0;
}