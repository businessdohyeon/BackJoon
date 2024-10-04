/*
BackJoon No.
#3584
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> getAncestors(const vector<int>& parent, const int target){
	vector<int> result;

	for(int i=target; i != -1; i = parent[i]){
		result.push_back(i);
	}

	return result;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int testNum;
	cin >> testNum;

	for(int _=0; _<testNum; ++_){
		int nodeNum;
		cin >> nodeNum;

		vector<int> parent(nodeNum+1, -1);
		for(int i=0; i<nodeNum-1; ++i){
			int a, b;
			cin >> a >> b;
			parent[b] = a;
		}

		int target0, target1;
		cin >> target0 >> target1;

		vector<int> ancestors0 = getAncestors(parent, target0);
		vector<int> ancestors1 = getAncestors(parent, target1);

		int idx0 = ancestors0.size() - 1;
		int idx1 = ancestors1.size() - 1;
		while(ancestors0[idx0] == ancestors1[idx1] && idx0 >= 0 && idx1 >= 0){
			--idx0;
			--idx1;
		}

		int ans = ancestors0[idx0+1];
		cout << ans << '\n';
	}

	return 0;
}