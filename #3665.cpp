/*
BackJoon No.
#3665
*/

#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int testNum;
	cin >> testNum;

	for(int _=0; _<testNum; ++_){
		int teamNum;
		cin >> teamNum;

		bool graph[teamNum+1][teamNum+1];
		memset(graph, false, sizeof(graph));

		int lastYear[teamNum];
		for(int i=0; i<teamNum; ++i){
			cin >> lastYear[i];
			for(int j=0; j<i; ++j){
				graph[lastYear[j]][lastYear[i]] = true;
			}
		}

		int changeNum;
		cin >> changeNum;
		for(int __=0; __<changeNum; ++__){
			int a, b;
			cin >> a >> b;
			graph[a][b] = !graph[a][b];
			graph[b][a] = !graph[b][a];
		}

		int inDegree[teamNum+1];
		memset(inDegree, 0, sizeof(inDegree));
		for(int from=1; from<=teamNum; ++from){
			for(int to=1; to<=teamNum; ++to){
				if(graph[from][to]){
					++inDegree[to];
				}
			}
		}

		vector<int> result;
		queue<int> q;
		for(int i=1; i<=teamNum; ++i){
			if(inDegree[i] == 0){
				q.push(i);
			}
		}

		for(int __=0; __<teamNum; ++__){
			if(q.empty())		break;
			
			int front = q.front();
			q.pop();

			result.push_back(front);

			for(int to=1; to<=teamNum; ++to){
				if(graph[front][to]){
					--inDegree[to];
					if(inDegree[to] == 0){
						q.push(to);
					}
				}
			}
		}

		if(result.size() != teamNum){
			cout << "IMPOSSIBLE\n";
			continue;
		}

		for(const auto e : result){
			cout << e << ' ';
		}
		cout << '\n';
	}

	return 0;
}