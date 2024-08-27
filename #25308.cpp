/*
BackJoon No.
#25308
*/

#include <iostream>
#include <cmath>

using namespace std;

int stat[8];
bool isVisited[8];
int seq[8];
int ans;

void dfs(int depth = 0){
	if(depth == 8){
		for(int i = 0; i<8; ++i){
			double start = seq[i];
			double mid = seq[(i+1) % 8];
			double end = seq[(i+2) % 8];

			if(mid < start*end/(start+end) * sqrt(2))	return;
		}

		++ans;
		return;
	}

	for(int i=0; i<8; ++i){
		if(isVisited[i])	continue;

		isVisited[i] = true;
		seq[depth] = stat[i];

		dfs(depth+1);

		isVisited[i] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	for(int i=0; i<8; ++i)
		cin >> stat[i];

	dfs();

	cout << ans;

	return 0;
}