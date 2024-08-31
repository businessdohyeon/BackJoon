/*
BackJoon No.
#7869
*/

#include <iostream>
#include <cmath>

using namespace std;

typedef pair<double, double> Pos;
struct Circle{
	Pos center;
	double radius;
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	Circle a, b;
	cin >> a.center.first >> a.center.second >> a.radius;
	cin >> b.center.first >> b.center.second >> b.radius;

	if(a.radius > b.radius)		swap(a, b);

	double centerDist = sqrt(pow(a.center.first - b.center.first, 2)+pow(a.center.second - b.center.second, 2));

	double ans;
	if(centerDist >= a.radius + b.radius){
		ans = 0;
	}else if(centerDist + a.radius <= b.radius){
		ans = pow(a.radius, 2) * M_PI;
	}else{
		double thetaA = 2 * acos((pow(a.radius, 2) + pow(centerDist, 2) - pow(b.radius, 2)) / (2*a.radius*centerDist));
		double areaA = (thetaA - sin(thetaA)) * pow(a.radius, 2) / 2;

		double thetaB = 2 * acos((pow(b.radius, 2) + pow(centerDist, 2) - pow(a.radius, 2)) / (2*b.radius*centerDist));
		double areaB = (thetaB - sin(thetaB)) * pow(b.radius, 2) / 2;

		ans = areaA + areaB;
	}

	cout.precision(3);
	cout << fixed << ans;

	return 0;
}