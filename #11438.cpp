/*
BackJoon No.
#11438
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

constexpr int RANGE_MAX = 1e5;
constexpr int LOGGED = 17;
constexpr int EMPTY = 0;

int nodeNum;
vector<int> graph[RANGE_MAX+1];
int depth[RANGE_MAX+1];
bool isVisited[RANGE_MAX+1];
int sparseTable[LOGGED+1][RANGE_MAX+1];

void dfs(int root, int value){
	if(isVisited[root])		return;

	depth[root] = value;
	isVisited[root] = true;

	for(auto e : graph[root]){
		if(isVisited[e])	continue;

		sparseTable[0][e] = root;
		dfs(e, value+1);
	}
}

void makeSparseTable(){
	for(int power=1; power<=LOGGED; ++power){
		for(int node=1; node<=nodeNum; ++node){
			sparseTable[power][node] = sparseTable[power-1][sparseTable[power-1][node]];
		}
	}
}

int nthTraceBack(int target, int n){
	int result = target;

	for(int power=0; n != 0; ++power, n /= 2){
		if(n%2){
			result = sparseTable[power][result];
		}
	}

	return result;
}

int findLCA(int a, int b){
	int minDepth = min(depth[a], depth[b]);

	a = nthTraceBack(a, depth[a] - minDepth);
	b = nthTraceBack(b, depth[b] - minDepth);

	if(a == b)		return a;

	for(int power=log2(nodeNum); power>=0; --power){
		if(sparseTable[power][a] == EMPTY 
			|| sparseTable[power][b] == EMPTY
			|| sparseTable[power][a] == sparseTable[power][b]){
			continue;
		}

		a = sparseTable[power][a];
		b = sparseTable[power][b];
	}

	return sparseTable[0][a];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> nodeNum;

	for(int _=0; _<nodeNum-1; ++_){
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	dfs(1, 0);

	makeSparseTable();

	int testNum;
	cin >> testNum;

	for(int _=0; _<testNum; ++_){
		int a, b;
		cin >> a >> b;
		cout << findLCA(a, b) << '\n';
	}

	return 0;
}