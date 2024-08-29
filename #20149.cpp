/*
BackJoon No.
#20149
*/

#include <iostream>
#include <algorithm>

using namespace std;

typedef pair<long long int, long long int> Pos;

int ccw(Pos a, Pos b, Pos c){
	long long int cal = (a.first*b.second + b.first*c.second + c.first*a.second) - 
		(b.first*a.second + c.first*b.second + a.first*c.second);
	return int(cal > 0) - int(cal < 0);
}
long long int determinant(Pos a, Pos b){
	return ((a.first*b.second - a.second*b.first));
}
void intersection(Pos a0, Pos a1, Pos b0, Pos b1){
	double divisor = (a0.first-a1.first) * (b0.second-b1.second) - (a0.second-a1.second) * (b0.first-b1.first);
	if(divisor == 0){
		if(a1 == b0 && a0 <= b0){
			cout << '\n' << a1.first << ' ' << a1.second;
		}else if(a0 == b1 && a1 >= b1){
			cout << '\n' << a0.first << ' ' << a0.second;
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

	Pos a[2], b[2];
	for(int i=0; i<2; ++i)
		cin >> a[i].first >> a[i].second;
	for(int i=0; i<2; ++i)
		cin >> b[i].first >> b[i].second;

	if(a[0] > a[1])	swap(a[0], a[1]);
	if(b[0] > b[1])	swap(b[0], b[1]);

	int cal1 = ccw(a[0], a[1], b[0])*ccw(a[0], a[1], b[1]);
	int cal2 = ccw(b[0], b[1], a[0])*ccw(b[0], b[1], a[1]);
	if(cal1 == 0 && cal2 == 0){
		if(a[0] <= b[1] && a[1] >= b[0]){
			cout << 1;
			intersection(a[0], a[1], b[0], b[1]);
		}else{
			cout << 0;
		}
	}else{
		if(cal1 <= 0 && cal2 <= 0){
			cout << 1;
			intersection(a[0], a[1], b[0], b[1]);
		}else{
			cout << 0;
		}
	}

	return 0;
}