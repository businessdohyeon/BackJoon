/*
BackJoon No.
#20149
*/

#include <iostream>
#include <algorithm>

using namespace std;

typedef pair<long long int, long long int> Pos;
typedef pair<Pos, Pos> Line;

int ccw(const Pos& a, const Pos& b, const Pos& c){
	long long int cal = (a.first*b.second + b.first*c.second + c.first*a.second) - 
		(b.first*a.second + c.first*b.second + a.first*c.second);
	return int(cal > 0) - int(cal < 0);
}
bool isMeeting(const Line& a, const Line& b){
	int ccwAtoB0 = ccw(a.first, a.second, b.first);
	int ccwAtoB1 = ccw(a.first, a.second, b.second);
	int ccwBtoA0 = ccw(b.first, b.second, a.first);
	int ccwBtoA1 = ccw(b.first, b.second, a.second);

	if(ccwAtoB0 != ccwAtoB1 && ccwBtoA0 != ccwBtoA1)	return true;

	if(ccwAtoB0*ccwAtoB1 == 0 && ccwBtoA0*ccwBtoA1 == 0
		&& a.first <= b.second && b.first <= a.second){
		return true;
	}

	return false;
}
long long int determinant(const Pos& a, const Pos& b){
	return ((a.first*b.second - a.second*b.first));
}
void tryPrintIntersection(const Line& a, const Line& b){
	const Pos& a0 = a.first;
	const Pos& a1 = a.second;
	const Pos& b0 = b.first;
	const Pos& b1 = b.second;

	double divisor = (a0.first-a1.first) * (b0.second-b1.second) - (a0.second-a1.second) * (b0.first-b1.first);
	if(divisor == 0){
		if(a1 == b0 && a0 <= b0){
			cout << '\n' << a1.first << ' ' << a1.second;
		}else if(a0 == b1 && a1 >= b1){
			cout << '\n' << a0.first << ' ' << a0.second;
		}else{
			// print nothin'
		}
	}else{
		double commonX = ((determinant(a0, a1)*(b0.first-b1.first)) - (determinant(b0, b1)*(a0.first-a1.first))) / divisor;
		double commonY = ((determinant(a0, a1)*(b0.second-b1.second)) - (determinant(b0, b1)*(a0.second-a1.second))) / divisor;

		cout.precision(9);
		cout << fixed << '\n' << commonX << ' ' << commonY;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	Line a, b;
	cin >> a.first.first >> a.first.second >> a.second.first >> a.second.second;
	cin >> b.first.first >> b.first.second >> b.second.first >> b.second.second;

	if(a.first > a.second)	swap(a.first, a.second);
	if(b.first > b.second)	swap(b.first, b.second);

	if(isMeeting(a, b)){
		cout << 1;
		tryPrintIntersection(a, b);
	}else{
		cout << 0;
	}

	return 0;
}