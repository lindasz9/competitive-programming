#include <bits/stdc++.h>
using namespace std;
using ll=long long;

// Point structure
struct Point{
	ll x,y;
	Point(ll xx=0,ll yy=0):x(xx),y(yy){}
	Point operator-(const Point& p)const{
		return Point(x-p.x, y-p.y); // vector subtraction
	}
};

// Determine direction using cross product
int direction(Point a, Point b){
	ll s = a.y*b.x - a.x*b.y; 
	return (s>0) - (s<0); // 1 = positive, -1 = negative, 0 = zero
}

int main() {
	int t; cin>>t; // number of test cases
	while(t--){
		Point a,b,c;
		cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
		// if cross product positive => c is on the right
		if(direction(b-a, c-a) > 0) cout<<"RIGHT\n";
		// if negative => c is on the left
		else if(direction(b-a, c-a) < 0) cout<<"LEFT\n";
		else cout<<"TOUCH\n"; // if zero => point is on the line
	}
}
