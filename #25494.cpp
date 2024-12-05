/*
BackJoon No.
#25494
*/

#include <iostream>

using namespace std;

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int testNum;
	cin >> testNum;

	for(int _=0; _<testNum; ++_){
		int a, b, c;
		cin >> a >> b >> c;

		int ans = 0;
		for(int x=1; x<=a; ++x){
			for(int y=1; y<=b; ++y){
				for(int z=1; z<=c; ++z){
					if(x%y == y%z && y%z == z%x){
						++ans;
					}
				}
			}
		}

		cout << ans << '\n';
	}


	return 0;
}