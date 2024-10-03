/*
BackJoon No.
#1766
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int nodeNum, infoNum;
	cin >> nodeNum >> infoNum;

	vector<int> graph[nodeNum+1];
	vector<int> inDegree(nodeNum+1, 0);
	for(int _=0; _<infoNum; ++_){
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		++inDegree[b];
	}

	vector<int> result;

	priority_queue<int> pq;
	for(int i=1; i<=nodeNum; ++i){
		if(inDegree[i] == 0){
			pq.push(-i);
		}
	}

	for(int _=0; _<nodeNum; ++_){
		if(pq.empty())		return -1;

		int front = -pq.top();
		pq.pop();

		result.push_back(front);

		for(auto e : graph[front]){
			--inDegree[e];
			if(inDegree[e] == 0){
				pq.push(-e);
			}
		}
	}
	
	for(auto e : result){
		cout << e << ' ';
	}

	return 0;
}