/*
BackJoon No.
#3977
*/

#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

constexpr int INITIAL_VALUE = -1;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int testNum;
	cin >> testNum;

	for(int _=0; _<testNum; ++_){
		int nodeNum, edgeNum;
		cin >> nodeNum >> edgeNum;

		vector<int> graph[nodeNum];
		for(int __=0; __<edgeNum; ++__){
			int a, b;
			cin >> a >> b;
			graph[a].push_back(b);
		}

		int sccCnt = 0;
		vector<int> sccInfo(nodeNum, INITIAL_VALUE);

		int visitCnt = 0;
		vector<int> whenVisited(nodeNum, INITIAL_VALUE);
		vector<int> dfsStack;
		function<int(int)> tarjan = [&](int root)->int{
			++visitCnt;
			whenVisited[root] = visitCnt;

			dfsStack.push_back(root);

			int minVisitCnt = whenVisited[root];
			for(const auto& e : graph[root]){
				if(whenVisited[e] == INITIAL_VALUE){
					minVisitCnt = min(minVisitCnt, tarjan(e));
				}else if(sccInfo[e] == INITIAL_VALUE){
					minVisitCnt = min(minVisitCnt, whenVisited[e]);
				}else{
					// do nothin'
				}
			}

			if(minVisitCnt == whenVisited[root]){
				while(true){
					int top = dfsStack.back();
					dfsStack.pop_back();

					sccInfo[top] = sccCnt;

					if(top == root)		break;
				}

				++sccCnt;
			}

			return minVisitCnt;
		};


		for(int node=0; node<nodeNum; ++node){
			if(whenVisited[node] != INITIAL_VALUE)		continue;
			
			tarjan(node);
		}

		vector<int> sccIndegree(sccCnt, 0);
		for(int node=0; node<nodeNum; ++node){
			for(const auto& e : graph[node]){
				if(sccInfo[node] != sccInfo[e]){
					++sccIndegree[sccInfo[e]];
				}
			}
		}

		int aptScc = INITIAL_VALUE;
		bool isOnly = true;
		for(int scc=0; scc<sccCnt; ++scc){
			if(sccIndegree[scc] == 0){
				if(aptScc != INITIAL_VALUE){
					isOnly = false;
					break;
				}else{
					aptScc = scc;
				}
			}
		}

		if(isOnly){
			for(int node=0; node<nodeNum; ++node){
				if(sccInfo[node] == aptScc){
					cout << node << '\n';
				}
			}
		}else{
			cout << "Confused" << '\n';
		}
		cout << '\n';
	}

	return 0;
}