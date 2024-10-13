/*
BackJoon No.
#2150
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int nodeNum, edgeNum;
	cin >> nodeNum >> edgeNum;
	
	vector<vector<int>> graph(nodeNum+1);
	vector<vector<int>> inversedGraph(nodeNum+1);
	for(int _=0; _<edgeNum; ++_){
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		inversedGraph[b].push_back(a);
	}

	vector<vector<int>> sccVec;
	vector<bool> isVisited(nodeNum+1, false);
	vector<int> dfsStack;

	function<void(int)> dfs = [&](int root)->void{
		if(isVisited[root])		return;

		isVisited[root] = true;

		for(auto e : graph[root]){
			if(isVisited[e])		continue;

			dfs(e);
		}

		dfsStack.push_back(root);
	};

	for(int node=1; node<=nodeNum; ++node){
		dfs(node);
	}

	function<void(int, vector<int>&)> inversedDfs = [&](int root, vector<int>& result)->void{
		if(isVisited[root])		return;

		isVisited[root] = true;
		result.push_back(root);

		for(auto e : inversedGraph[root]){
			if(isVisited[e])		continue;

			inversedDfs(e, result);
		}
	};

	fill(isVisited.begin(), isVisited.end(), false);
	while(!dfsStack.empty()){
		int back = dfsStack.back();
		dfsStack.pop_back();

		vector<int> result;
		inversedDfs(back, result);
		if(!result.empty()){
			sccVec.push_back(result);
		}
	}

	for(auto& scc : sccVec){
		sort(scc.begin(), scc.end());
	}
	sort(sccVec.begin(), sccVec.end());

	cout << sccVec.size() << '\n';
	for(const auto& scc : sccVec){
		for(const auto& e : scc){
			cout << e << ' ';
		}
		cout << -1 << '\n';
	}

	return 0;
}