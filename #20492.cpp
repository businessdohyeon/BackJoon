/*
BackJoon No.
#20492
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	long long int n;
	cin >> n;
	cout << setprecision(0) << fixed << (1-0.22) * n << ' ' << (1 - 0.2*0.22) * n;

	return 0;
}