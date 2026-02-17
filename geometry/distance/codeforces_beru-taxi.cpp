#include <bits/stdc++.h>
using namespace std;

// Point structure
struct Point{
	int x,y;
	Point(int xx=0,int yy=0):x(xx),y(yy){}
};

// Euclidean distance between two points
float pit(Point a, Point b){
	int dx = a.x - b.x;
	int dy = a.y - b.y;
	return sqrt(dx*dx + dy*dy); // distance formula
}

int main() {
	Point p; cin >> p.x >> p.y; // Vasiliy's home
	int n; cin >> n;             // number of available taxis

	float ans = FLT_MAX;         // minimum time initialized to max float
	while(n--){
		int v;
		Point a; cin >> a.x >> a.y >> v; // taxi coordinates and speed
		float time = pit(p, a) / v;     // time = distance / speed
		ans = min(ans, time);           // keep the minimum time
	}

	cout << fixed << setprecision(10) << ans << '\n'; // output with precision
}
