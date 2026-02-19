#include <bits/stdc++.h>
using namespace std;
#define int long long

// Point structure
struct Point{
	int x,y;
	Point(int x2=0,int y2=0):x(x2),y(y2){}
	Point operator-(const Point& p){
		return Point(x-p.x, y-p.y); // vector subtraction
	}
};

// Cross product to determine orientation
int direction(Point a, Point b){
	int s = a.x*b.y - a.y*b.x;
	return (s>0) - (s<0); // 1 = positive, -1 = negative, 0 = collinear
}

// Check if point c lies between a and b in both x and y
bool between(Point a, Point b, Point c){
	return (min(a.x,b.x) <= c.x && max(a.x,b.x) >= c.x) &&
	       (min(a.y,b.y) <= c.y && max(a.y,b.y) >= c.y);
}

// Check if point c is on segment ab
bool on(Point a, Point b, Point c){
	return (a.y-c.y)*(a.x-b.x) == (a.y-b.y)*(a.x-c.x) && between(a,b,c);
}

int main() {
	int t; cin>>t; // number of test cases
	while(t--){
		Point a,b,c,d;
		cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> d.x >> d.y;

		// check if any endpoint lies on the other segment
		if(on(a,b,c) || on(a,b,d) || on(c,d,a) || on(c,d,b)){
			cout<<"YES\n"; 
			continue;
		}

		// check orientations for intersection
		int ang1 = direction(b-a, b-c), ang2 = direction(b-a, b-d);
		if(ang1 == ang2){ cout<<"NO\n"; continue; }
		ang1 = direction(c-d, c-a), ang2 = direction(c-d, c-b);
		if(ang1 == ang2){ cout<<"NO\n"; continue; }

		cout<<"YES\n"; // segments intersect
	}
}
