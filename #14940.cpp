/*
BackJoon No.
#14940
*/

#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

const int RANGE_MAX = 1000;
const int dRow[] = {-1, 1, 0, 0};
const int dCol[] = {0, 0, -1, 1};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int width, height;
	cin >> height >> width;

	int board[height][width];

	int ans[height][width];
	memset(ans, -1, sizeof(ans));

	bool isVisited[height][width];
	memset(isVisited, false, sizeof(isVisited));

	int destRow, destCol;
	for(int row=0; row<height; ++row){
		for(int col=0; col<width; ++col){
			cin >> board[row][col];

			if(board[row][col] == 0){
				ans[row][col] = 0;
				isVisited[row][col] = true;
			}else if(board[row][col] == 2){
				destRow = row;
				destCol = col;
			}else{
				// do nothin'
			}
		}
	}

	queue<pair<int,int>> q[2];
	int value = 0;

	int cur = 0, next = 1;
	q[cur].push({destRow, destCol});

	while(!q[cur].empty()){
		auto [row, col] = q[cur].front();
		q[cur].pop();

		if(!isVisited[row][col]){
			ans[row][col] = value;
			isVisited[row][col] = true;

			for(int i=0; i<4; ++i){
				int nextRow = row + dRow[i];
				int nextCol = col + dCol[i];

				if(nextRow < 0 || nextRow >= height
					|| nextCol < 0 || nextCol >= width){
					continue;
				}

				if(isVisited[nextRow][nextCol])		continue;

				q[next].push({nextRow, nextCol});
			}
		}

		if(q[cur].empty()){
			++value;
			swap(cur, next);
		}
	}


	for(int row=0; row<height; ++row){
		for(int col=0; col<width; ++col){
			cout << ans[row][col] << ' ';
		}
		cout << '\n';
	}

	return 0;
}