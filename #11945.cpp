/*
BackJoon No.
#11945
*/

#include <iostream>

using namespace std;

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int n, m;
	cin >> n >> m;

	for(int _=0; _<n; ++_){
		char arr[m];
		for(int j=0; j<m; ++j){
			cin >> arr[j];
		}

		for(int i=m-1; i>=0; --i){
			cout << arr[i];
		}
		cout << '\n';
	}

	return 0;
}