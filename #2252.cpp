/*
BackJoon No.
#2252
*/

#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>

using namespace std;

constexpr int RANGE_MAX = 32000;

int nodeNum, m;
vector<int> graph[RANGE_MAX+1];
int inDegree[RANGE_MAX+1];
vector<int> result;

void topologicalSort(){
	queue<int> q;

	for(int i=1; i<=nodeNum; ++i){
		if(inDegree[i] == 0){
			q.push(i);
		}
	}

	for(int _=0; _<nodeNum; ++_){
		if(q.empty())		return;

		int front = q.front();
		q.pop();

		result.push_back(front);

		for(const auto e : graph[front]){
			--inDegree[e];

			if(inDegree[e] == 0){
				q.push(e);
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> nodeNum >> m;

	memset(inDegree, 0, sizeof(inDegree));
	for(int _=0; _<m; ++_){
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		++inDegree[b];
	}

	topologicalSort();

	for(const auto e : result){
		cout << e << ' ';
	}

	return 0;
}