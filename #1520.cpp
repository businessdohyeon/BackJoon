/*
BackJoon No
#1520
*/

#include <iostream>

using namespace std;

int dp[500][500];
int n, m;
int input[500][500];
    
int solve(int row, int col){
    if(row == n-1 && col == m-1)    return 1;
    else if(dp[row][col] != -1)     return dp[row][col];

    dp[row][col] = 0;

    if(row>0 && input[row][col] > input[row-1][col])
        dp[row][col] += solve(row-1, col);
    if(col>0 && input[row][col] > input[row][col-1])
        dp[row][col] += solve(row, col-1);
    if(row<n-1 && input[row][col] > input[row+1][col])
        dp[row][col] += solve(row+1, col);
    if(col<m-1 && input[row][col] > input[row][col+1])
        dp[row][col] += solve(row, col+1);

    return dp[row][col];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    for(int i=0; i<500; ++i)
        for(int j=0; j<500; ++j)
            dp[i][j] = -1;

    cin >> n >> m;

    for(int i=0; i<n; ++i)
        for(int j=0; j<m; ++j)
            cin >> input[i][j];

    cout << solve(0, 0);

    return 0;
}