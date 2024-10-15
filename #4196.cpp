/*
BackJoon No.
#4196
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int testNum;
	cin >> testNum;

	for(int _=0; _<testNum; ++_){
		int nodeNum, edgeNum;
		cin >> nodeNum >> edgeNum;

		vector<vector<int>> graph(nodeNum+1);
		for(int __=0; __<edgeNum; ++__){
			int a, b;
			cin >> a >> b;
			graph[a].push_back(b);
		}

		int ans = 0;
		vector<bool> isVisited(nodeNum+1, false);
		vector<int> dfsStack;

		function<void(int)> setDfsStack = [&](int root)->void{
			if(isVisited[root])		return;

			isVisited[root] = true;

			for(const auto& e : graph[root]){
				if(isVisited[e])		continue;

				setDfsStack(e);
			}

			dfsStack.push_back(root);
		};

		for(int node=1; node<=nodeNum; ++node){
			setDfsStack(node);
		}

		fill(isVisited.begin(), isVisited.end(), false);

		function<void(int)> dfs = [&](int root)->void{
			if(isVisited[root])		return;

			isVisited[root] = true;	

			for(const auto& e : graph[root]){
				if(isVisited[e])		continue;

				dfs(e);
			}
		};

		while(!dfsStack.empty()){
			int back = dfsStack.back();
			dfsStack.pop_back();

			if(isVisited[back])		continue;

			dfs(back);
			
			++ans;
		}

		cout << ans << '\n';
	}

	return 0;
}