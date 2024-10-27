/*
BackJoon No.
#3977
*/

#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

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

		vector<int> forwardGraph[nodeNum];
		vector<int> backwardGraph[nodeNum];
		for(int __=0; __<edgeNum; ++__){
			int a, b;
			cin >> a >> b;
			forwardGraph[a].push_back(b);
			backwardGraph[b].push_back(a);
		}

		vector<int> dfsStack;
		vector<bool> isVisited(nodeNum, false);
		function<void(int)> setDfsStack = [&](int root)->void{
			if(isVisited[root])		return;

			isVisited[root] = true;

			for(const auto& e : forwardGraph[root]){
				if(isVisited[e])	continue;

				setDfsStack(e);
			}

			dfsStack.push_back(root);
		};

		for(int node=0; node<nodeNum; ++node){
			setDfsStack(node);
		}

		vector<int> sccArr[nodeNum];
		int sccInfo[nodeNum];
		int sccNum = 0;
		fill(isVisited.begin(), isVisited.end(), false);
		
		while(!dfsStack.empty()){
			int top = dfsStack.back();
			dfsStack.pop_back();

			if(isVisited[top])		continue;

			function<void(int)> makeSCC = [&](int root)->void{
				if(isVisited[root])		return;

				isVisited[root] = true;
				sccInfo[root] = sccNum;
				sccArr[sccNum].push_back(root);

				for(const auto& e : backwardGraph[root]){
					if(isVisited[e])	continue;

					makeSCC(e);
				}
			};

			makeSCC(top);

			++sccNum;
		}

		vector<int> sccIndegree(sccNum, 0);
		for(int node=0; node<nodeNum; ++node){
			for(const auto& e : forwardGraph[node]){
				if(sccInfo[node] != sccInfo[e]){
					++sccIndegree[sccInfo[e]];
				}
			}
		}

		int aptScc = -1;
		bool isOnly = true;
		for(int scc=0; scc<sccNum; ++scc){
			if(sccIndegree[scc] == 0){
				if(aptScc != -1){
					isOnly = false;
					break;
				}else{
					aptScc = scc;
				}
			}
		}

		if(isOnly){
			sort(sccArr[aptScc].begin(), sccArr[aptScc].end());
			for(const auto& e : sccArr[aptScc]){
				cout << e << '\n';
			}
		}else{
			cout << "Confused" << '\n';
		}
		cout << '\n';
	}

	return 0;
}