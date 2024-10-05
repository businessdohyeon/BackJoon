/*
BackJoon No.
#17435
*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

constexpr int RANGE_MAX = log2(2e5) + 1;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int elmentNum;
	cin >> elmentNum;

	// sparseTable[n][x] = 2^n_th f(x)
	int sparseTable[RANGE_MAX+1][elmentNum+1];
	for(int i=1; i<=elmentNum; ++i){
		cin >> sparseTable[0][i];
	}

	for(int i=1; i<=RANGE_MAX; ++i){
		for(int j=1; j<=elmentNum; ++j){
			sparseTable[i][j] = sparseTable[i-1][sparseTable[i-1][j]];
		}
	}

	int queryNum;
	cin >> queryNum;
	for(int _=0; _<queryNum; ++_){
		int n, x;
		cin >> n >> x;

		for(int power=0; n != 0; ++power, n /= 2){
			if(n%2){
				x = sparseTable[power][x];
			}
		}

		cout << x << '\n';
	}

	return 0;
}