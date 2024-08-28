/*
BackJoon No.
#17387
*/

#include <iostream>

using namespace std;

typedef pair<long long int, long long int> Pos;

int ccw(Pos a, Pos b, Pos c){
	long long int cal = (a.first*b.second + b.first*c.second + c.first*a.second) - 
		(b.first*a.second + c.first*b.second + a.first*c.second);
	return int(cal > 0) - int(cal < 0);
}
bool isTargetPosOnLineSegment(Pos lineSegmentPos0, Pos lineSegmentPos1, Pos target){
	if(lineSegmentPos0.first < lineSegmentPos1.first){
		if(target.first < lineSegmentPos0.first)	return false;
		if(target.first > lineSegmentPos1.first)	return false;
	}else{
		if(target.first < lineSegmentPos1.first)	return false;
		if(target.first > lineSegmentPos0.first)	return false;
	}

	if(lineSegmentPos0.second < lineSegmentPos1.second){
		if(target.second < lineSegmentPos0.second)	return false;
		if(target.second > lineSegmentPos1.second)	return false;
	}else{
		if(target.second < lineSegmentPos1.second)	return false;
		if(target.second > lineSegmentPos0.second)	return false;
	}

	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	Pos a[2], b[2];
	for(int i=0; i<2; ++i)
		cin >> a[i].first >> a[i].second;
	for(int i=0; i<2; ++i)
		cin >> b[i].first >> b[i].second;

	int ccwAtoB0 = ccw(a[0], a[1], b[0]);
	int ccwAtoB1 = ccw(a[0], a[1], b[1]);
	int ccwBtoA0 = ccw(b[0], b[1], a[0]);
	int ccwBtoA1 = ccw(b[0], b[1], a[1]);

	bool ans = ((ccwAtoB0 != ccwAtoB1) && (ccwBtoA0 != ccwBtoA1))
		|| (ccwAtoB0 == 0 && isTargetPosOnLineSegment(a[0], a[1], b[0]))
		|| (ccwAtoB1 == 0 && isTargetPosOnLineSegment(a[0], a[1], b[1]))
		|| (ccwBtoA0 == 0 && isTargetPosOnLineSegment(b[0], b[1], a[0]))
		|| (ccwBtoA1 == 0 && isTargetPosOnLineSegment(b[0], b[1], a[1]));

	cout << int(ans);

	return 0;
}