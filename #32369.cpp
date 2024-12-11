/*
BackJoon No.
#32369
*/

#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, a, b;
	cin >> n >> a >> b;

	int ching = 1;
	int bi = 1;
	for(int i=0; i<n; ++i){
		ching += a;
		bi += b;

		if(ching < bi){
			swap(ching, bi);
		}else if(ching == bi){
			--bi;
		}else{
			// do nothin'
		}
	}

	cout << ching << ' ' << bi;

	return 0;
}