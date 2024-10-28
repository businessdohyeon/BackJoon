/*
BackJoon No.
#4013
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int RANGE_MAX = 5e5;


int nodeNum, edgeNum;
vector<int> graph[RANGE_MAX+1];
long long money[RANGE_MAX+1];
int start, restaurantNum;
bool isRestaurant[RANGE_MAX+1];

int sccCnt = 0;
int sccInfo[RANGE_MAX+1];

int visitId = 0;
int visitIdArr[RANGE_MAX+1];
vector<int> tarjanStack;

long long sccMoeny[RANGE_MAX+1];

vector<int> sccGraph[RANGE_MAX+1];
bool isSccVisited[RANGE_MAX+1];
long long maxSum[RANGE_MAX+1];
bool isRestaurantIncluded[RANGE_MAX+1];
long long dp[RANGE_MAX+1];
long long ans = 0;


void getInput(){
	cin >> nodeNum >> edgeNum;

	for(int _=0; _<edgeNum; ++_){
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
	}

	for(int node=1; node<=nodeNum; ++node){
		cin >> money[node];
	}
	
	cin >> start >> restaurantNum;

	for(int _=0; _<restaurantNum; ++_){
		int restaurant;
		cin >> restaurant;
		isRestaurant[restaurant] = true;
	}
}

int tarjan(int root){
	++visitId;
	visitIdArr[root] = visitId;
	
	tarjanStack.push_back(root);

	int minVisitId = visitIdArr[root];
	for(const auto& e : graph[root]){
		if(visitIdArr[e] == 0){
			minVisitId = min(minVisitId, tarjan(e));
		}else if(sccInfo[e] == 0){
			minVisitId = min(minVisitId, visitIdArr[e]);
		}else{
			// do nothin'
		}
	}

	if(minVisitId == visitIdArr[root]){
		++sccCnt;

		while(!tarjanStack.empty()){
			int back = tarjanStack.back();
			tarjanStack.pop_back();

			sccInfo[back] = sccCnt;

			if(back == root)	break;
		}
	}

	return minVisitId;
}

void sccDfs(int root, long long total){
	isSccVisited[root] = true;

	maxSum[root] = max(maxSum[root], total);

	for(const auto& e : sccGraph[root]){
		long long nextTotal = total + sccMoeny[e];

		if(isSccVisited[e] && maxSum[e] > nextTotal){
			continue;
		}

		sccDfs(e, nextTotal);
	}
}



long long findans(int rootScc){
    long long &aptDp = dp[rootScc];

    if(aptDp!=-1) 	return aptDp;

    long long temp = 0;
    for (int next: sccGraph[rootScc]){
        temp = max(temp, findans(next));
    }

    if(temp == 0){
        if(!isRestaurantIncluded[rootScc]){
			return aptDp = 0;
		}else{
			return aptDp = sccMoeny[rootScc];
		}
    }

	return aptDp = temp + sccMoeny[rootScc];
}

void solve(){
	for(int node=1; node<=nodeNum; ++node){
		if(visitIdArr[node] == 0){
			tarjan(node);
		}
	}

	for(int node=1; node<=nodeNum; ++node){
		sccMoeny[sccInfo[node]] += money[node];

		if(isRestaurant[node]){
			isRestaurantIncluded[sccInfo[node]] = true;
		}

		for(const auto& e : graph[node]){
			if(sccInfo[node] != sccInfo[e]){
				sccGraph[sccInfo[node]].push_back(sccInfo[e]);
			}
		}
	}
	
	int startScc = sccInfo[start];

	memset(dp, -1, sizeof(dp));
	ans = findans(startScc);

	cout << ans;
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	getInput();

	solve();

	return 0;
}