/*
BackJoon No.
#13511
*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Item{
	int dest;
	long long cost;
};

const int RANGE_MAX = 1e5;
const int LOGGED = 16;
const int ROOT = 1;
const int INVALID_NODE = 0;

int nodeNum;
vector<pair<int,int>> graph[RANGE_MAX+1];
bool isVisited[RANGE_MAX+1];
int depth[RANGE_MAX+1];
Item sparseTable[LOGGED+1][RANGE_MAX+1];
int queryNum;

void dfs(int root, int depthValue){
	if(isVisited[root])		return;

	isVisited[root] = true;
	depth[root] = depthValue;

	for(auto child : graph[root]){
		if(isVisited[child.first])		continue;

		sparseTable[0][child.first].dest = root;
		sparseTable[0][child.first].cost = child.second;

		dfs(child.first, depthValue+1);
	}
}

void setSparseTable(){
	dfs(ROOT, 0);

	for(int power=1; power<=LOGGED; ++power){
		for(int node=1; node<=nodeNum; ++node){
			Item& start2mid = sparseTable[power-1][node];
			Item& mid2end = sparseTable[power-1][start2mid.dest];

			sparseTable[power][node].dest = mid2end.dest;
			sparseTable[power][node].cost = start2mid.cost + mid2end.cost;
		}
	}
}

pair<int,long long> solve1(int a, int b){
	long long totalCost = 0;

	auto tracebackByPower = [&](int& target, int power)->void{
		totalCost += sparseTable[power][target].cost;
		target = sparseTable[power][target].dest;
	};

	int& deeper = depth[a] > depth[b] ? a : b;
	int diff = abs(depth[a] - depth[b]);
	for(int power=0; diff>0; diff/=2, ++power){
		if(diff%2 == 0)		continue;

		tracebackByPower(deeper, power);
	}

	if(a == b)		return {a, totalCost};

	for(int power=LOGGED; power>=0; --power){
		if(sparseTable[power][a].dest == INVALID_NODE
			|| sparseTable[power][b].dest == INVALID_NODE
			|| sparseTable[power][a].dest == sparseTable[power][b].dest){
			continue;
		}

		tracebackByPower(a, power);
		tracebackByPower(b, power);
	}

	tracebackByPower(a, 0);
	tracebackByPower(b, 0);

	return {a, totalCost};
}

int solve2(int a, int b, int k){
	auto [lca, totalCost] = solve1(a, b);

	int pathLenA = depth[a] - depth[lca];
	int pathLenB = depth[b] - depth[lca];
	
	auto traceback = [](int& target, int n)->void{
		for(int power=0; n>0; n/=2, ++power){
			if(n%2 == 0)		continue;

			target = sparseTable[power][target].dest;
		}
	};


	if(k == pathLenA){
		return lca;
	}else if(k < pathLenA){
		traceback(a, k);
		return a;
	}else{
		traceback(b, pathLenA + pathLenB - k);
		return b;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> nodeNum;
	
	for(int _=0; _<nodeNum-1; ++_){
		int a, b;
		long long w;
		cin >> a >> b >> w;
		graph[a].push_back({b, w});
		graph[b].push_back({a, w});
	}

	setSparseTable();

	cin >> queryNum;

	for(int _=0; _<queryNum; ++_){
		int mode;
		cin >> mode;
		
		if(mode == 1){
			int u, v;
			cin >> u >> v;

			auto [lca, totalCost] = solve1(u, v);

			cout << totalCost << '\n';
		}else if(mode == 2){
			int u, v, k;
			cin >> u >> v >> k;
			
			int result = solve2(u, v, k-1);

			cout << result << '\n';
		}else{
			// do nothin'
		}
	}

	return 0;
}