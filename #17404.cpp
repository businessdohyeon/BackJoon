/*
BackJoon No.
#17404
*/

#include <iostream>
#include <algorithm>

using namespace std;

constexpr int COLOR_MAX = 3;
constexpr int INF = 1000001;

pair<int, int> getOtherColor(int n){
	return {(n+1) % COLOR_MAX, (n+2) % COLOR_MAX};
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int houseNum;
	cin >> houseNum;

	int cost[houseNum][COLOR_MAX];
	for(int i=0; i<houseNum; ++i)
		for(int j=0; j<COLOR_MAX; ++j)
			cin >> cost[i][j];

	int ans = INF;
	int dp[houseNum][COLOR_MAX];
	for(int firstColor=0; firstColor<COLOR_MAX; ++firstColor){
		auto [otherColor0, otherColor1] = getOtherColor(firstColor);
		
		dp[0][firstColor] = cost[0][firstColor];
		dp[0][otherColor0] = INF;
		dp[0][otherColor1] = INF;

		for(int curHouse=1; curHouse<houseNum; ++curHouse){
			for(int curColor=0; curColor<COLOR_MAX; ++curColor){
				auto [otherColor2, otherColor3] = getOtherColor(curColor);
				dp[curHouse][curColor] = min(dp[curHouse-1][otherColor2], dp[curHouse-1][otherColor3]) + cost[curHouse][curColor];
			}
		}

		ans = min(ans, min(dp[houseNum-1][otherColor0], dp[houseNum-1][otherColor1]));
	}

	cout << ans;

	return 0;
}