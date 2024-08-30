/*
BackJoon No.
#2162
*/

#include <iostream>
#include <algorithm>

using namespace std;

typedef pair<int, int> Pos;
typedef pair<Pos, Pos> Line;

int ccw(const Pos& a, const Pos& b, const Pos& c){
	int cal = (a.first*b.second + b.first*c.second + c.first*a.second)
		- (b.first*a.second + c.first*b.second + a.first*c.second);
	return int(cal > 0) - int(cal < 0);
}
bool isMeeting(const Line& a, const Line& b){
	int ccwAtoB0 = ccw(a.first, a.second, b.first);
	int ccwAtoB1 = ccw(a.first, a.second, b.second);
	int ccwBtoA0 = ccw(b.first, b.second, a.first);
	int ccwBtoA1 = ccw(b.first, b.second, a.second);

	if(ccwAtoB0 != ccwAtoB1 && ccwBtoA0 != ccwBtoA1)	return true;
	
	if(ccwAtoB0*ccwAtoB1 == 0 && ccwBtoA0*ccwBtoA1 == 0
		&& min(a.first, a.second) <= max(b.first, b.second) 
		&& min(b.first, b.second) <= max(a.first, a.second)){
		return true;
	}

	return false;
}
int findRootViaUnionFind(int unionFindArr[], int target){
	if(unionFindArr[target] == target)		return target;

	int root = findRootViaUnionFind(unionFindArr, unionFindArr[target]);
	unionFindArr[target] = root;
	return root;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int lineNum;	
	cin >> lineNum;

	int unionFindArr[lineNum];
	for(int i=0; i<lineNum; ++i)
		unionFindArr[i] = i;

	Line lineArr[lineNum];
	for(int i=0; i<lineNum; ++i){
		Line& curLine = lineArr[i];
		cin >> curLine.first.first >> curLine.first.second >> curLine.second.first >> curLine.second.second;

		for(int j=0; j<i; ++j)
			if(isMeeting(curLine, lineArr[j]))
				unionFindArr[findRootViaUnionFind(unionFindArr, i)] = findRootViaUnionFind(unionFindArr, j);
	}

	int linePerGroup[lineNum];
	fill(linePerGroup, linePerGroup+lineNum, 0);

	for(int i=0; i<lineNum; ++i)
		++linePerGroup[findRootViaUnionFind(unionFindArr, i)];

	int groupNum = 0;
	int groupMaxVal = 0;
	for(int i=0; i<lineNum; ++i){
		int val = linePerGroup[i];

		if(val > 0)				++groupNum;
		if(val > groupMaxVal)	groupMaxVal = val;
	}

	cout << groupNum << '\n' << groupMaxVal;

	return 0;
}