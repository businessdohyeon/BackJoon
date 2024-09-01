/*
BackJoon No.
#1069
*/

#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

typedef pair<int, int> Pos;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	const double WALK_SPEED = 1.0;

	Pos from;
	cin >> from.first >> from.second;
	
	double jumpVal, jumpTime;
	cin >> jumpVal >> jumpTime;

	const double dist = sqrt(pow(from.first, 2) + pow(from.second, 2));

	double ans;
	if(WALK_SPEED >= jumpVal / jumpTime){
		ans = dist;
	}else{
		int maxJumpWhithinDist = dist / jumpVal;
		
		if(maxJumpWhithinDist == 0){
			ans = min(dist, min(2*jumpTime, jumpTime + jumpVal - dist));
		}else{
			ans = min(jumpTime*maxJumpWhithinDist + dist - jumpVal*maxJumpWhithinDist, jumpTime * (maxJumpWhithinDist+1));
		}
	}

	cout.precision(20);
	cout << fixed << ans;

	return 0;
}