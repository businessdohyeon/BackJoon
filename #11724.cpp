/*
BackJoon No.
#11724
*/

#include <iostream>
#include <vector>
#include <functional>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int nodeNum, edgeNum;
	cin >> nodeNum >> edgeNum;

	vector<int> graph[nodeNum+1];
	for(int i=0; i<edgeNum; ++i){
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	vector<bool> isVisited(nodeNum+1, false);
	function<void(int)> dfs = [&](int root)->void{
		if(isVisited[root])		return;

		isVisited[root] = true;

		for(const auto& e : graph[root]){
			if(isVisited[e])	continue;

			dfs(e);
		}
	};

	int ans = 0;
	for(int i=1; i<=nodeNum; ++i){
		if(isVisited[i])	continue;

		dfs(i);
		++ans;
	}

	cout << ans;

	return 0;
}