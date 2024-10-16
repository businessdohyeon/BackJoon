/*
BackJoon No.
#7568
*/

#include <iostream>
#include <vector>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	vector<pair<int,int>> v(n);
	for(int i=0; i<n; ++i){
		cin >> v[i].first >> v[i].second;
	}

	for(int i=0; i<n; ++i){
		int rank = 1;
		for(int j=0; j<n; ++j){
			if(v[j].first > v[i].first && v[j].second > v[i].second){
				++rank;
			}
		}
		cout << rank << ' ';
	}

	return 0;
}