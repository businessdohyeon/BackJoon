/*
BackJoon No.
#1074
*/

#include <iostream>
#include <cmath>

using namespace std;

int solve(int size, int row, int col){
	if(size == 2){
		return 2*row+col;
	}

	int halfSize = size/2;

	int rtmp = row >= halfSize;
	int ctmp = col >= halfSize;
	
	int offset = (2*rtmp + ctmp) * pow(halfSize, 2);

	return offset + solve(halfSize, row - rtmp*halfSize, col - ctmp*halfSize);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, r, c;
	cin >> n >> r >> c;

	int ans = solve(pow(2, n), r, c);

	cout << ans;

	return 0;
}