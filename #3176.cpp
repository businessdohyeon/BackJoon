/*
BackJoon No.
#3176
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Item{
	int dest, min, max;
};

constexpr int RANGE_MAX = 1e5;
constexpr int LOGGED = 16;
constexpr int ROOT = 1;
constexpr int INVALID_NODE = 0;
constexpr int LEN_MAX = 1e6;
constexpr int LEN_MIN = 0;

int nodeNum;
int testNum;
vector<pair<int,int>> graph[RANGE_MAX+1];
bool isVisited[RANGE_MAX+1];
int depth[RANGE_MAX+1];
Item sparseTable[LOGGED+1][RANGE_MAX+1];	// 2^n 회 거슬러 올라갔을 때 { 도달점, 최소, 최대 }

void dfs(int root, int depthValue){
	if(isVisited[root])		return;

	isVisited[root] = true;
	depth[root] = depthValue;

	for(auto child : graph[root]){
		if(isVisited[child.first])	continue;

		sparseTable[0][child.first] = { root, child.second, child.second};
		dfs(child.first, depthValue+1);
	}
}

void setSparseTable(){
	dfs(ROOT, 0);

	for(int power=1; power<=LOGGED; ++power){
		for(int node=1; node<=nodeNum; ++node){
			int mid = sparseTable[power-1][node].dest;
			sparseTable[power][node].dest = sparseTable[power-1][mid].dest;
			sparseTable[power][node].min = min(sparseTable[power-1][node].min, sparseTable[power-1][mid].min);
			sparseTable[power][node].max = max(sparseTable[power-1][node].max, sparseTable[power-1][mid].max);
		}
	}
}

pair<int,int> solve(int a, int b){
	int resultMin = LEN_MAX+1;
	int resultMax = LEN_MIN-1;

	auto traceBack = [&resultMin, &resultMax](int& target, int power)-> void{
		resultMin = min(resultMin, sparseTable[power][target].min);
		resultMax = max(resultMax, sparseTable[power][target].max);
		target = sparseTable[power][target].dest;
	};

	// 깊이 맞추기
	int& deeper = depth[a] > depth[b] ? a : b;
	int diff = abs(depth[a] - depth[b]);
	for(int power=0; diff>0; ++power, diff /= 2){
		if(diff % 2 == 0)	continue;

		traceBack(deeper, power);
	}

	// 깊이를 맞췄더니 동일한 경우 == 어느 하나가 상대의 조상인 경우
	if(a == b)		return {resultMin, resultMax};

	// 가능한 큰 단위로 계속 접어올리기
	for(int power=LOGGED; power >= 0; --power){
		if(sparseTable[power][a].dest == INVALID_NODE 
			|| sparseTable[power][b].dest == INVALID_NODE
			|| sparseTable[power][a].dest == sparseTable[power][b].dest){
			continue;
		}
		
		traceBack(a, power);
		traceBack(b, power);
	}

	// 한번 더 거슬러 올라가고, 값들 업데이트
	traceBack(a, 0);
	traceBack(b, 0);

	return {resultMin, resultMax};
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> nodeNum;
	
	for(int _=0; _<nodeNum-1; ++_){
		int a, b, len;
		cin >> a >> b >> len;
		graph[a].push_back({b, len});
		graph[b].push_back({a, len});
	}

	setSparseTable();
	
	cin >> testNum;

	for(int _=0; _<testNum; ++_){
		int a, b;
		cin >> a >> b;

		auto [resultMin, resultMax] = solve(a, b);
		cout << resultMin << ' ' << resultMax << '\n';
	}

	return 0;
}