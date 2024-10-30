/*
BackJoon No.
#21736
*/

#include <iostream>

using namespace std;

const int RANGE_MAX = 600;
const int dRow[] = {-1, 1, 0, 0};
const int dCol[] = {0, 0, -1, 1};

int height, width;
char board[RANGE_MAX][RANGE_MAX];
int startRow, startCol;
int meetCnt = 0;
bool isVisited[RANGE_MAX][RANGE_MAX];

void dfs(int rootRow, int rootCol){
	if(isVisited[rootRow][rootCol])		return;

	isVisited[rootRow][rootCol] = true;
	if(board[rootRow][rootCol] == 'P'){
		++meetCnt;
	}

	for(int i=0; i<4; ++i){
		int nextRow = rootRow + dRow[i];
		int nextCol = rootCol + dCol[i];

		if(nextRow<0 || nextRow>=height
			|| nextCol<0 || nextCol>=width
			|| isVisited[nextRow][nextCol]
			|| board[nextRow][nextCol] == 'X'){
			continue;
		}

		dfs(nextRow, nextCol);
	}
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> height >> width;

	for(int row=0; row<height; ++row){
		for(int col=0; col<width; ++col){
			cin >> board[row][col];

			if(board[row][col] == 'I'){
				startRow = row;
				startCol = col;
			}
		}
	}

	dfs(startRow, startCol);

	if(meetCnt == 0){
		cout << "TT";
	}else{
		cout << meetCnt;
	}

	return 0;
}