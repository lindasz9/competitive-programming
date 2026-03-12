#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Point{
    ll x, y;
    bool isB; // true if the point belongs to polygon B
    Point(ll xx=0, ll yy=0, bool BB=false): x(xx), y(yy), isB(BB) {}
    Point operator-(const Point& p) const {
        return Point(x-p.x, y-p.y);
    }
};

Point start;

// orientation of vectors a and b (cross product sign)
// 1 -> left turn, -1 -> right turn, 0 -> collinear
ll orientation(Point a, Point b){
    ll s = a.y*b.x - a.x*b.y;
    return (s>0) - (s<0);
}

// squared distance between points a and b
ll dist2(Point a, Point b){
    Point c = a-b;
    return c.x*c.x + c.y*c.y;
}

// comparator for sorting points by polar angle around 'start'
bool cmp(Point a, Point b){
    ll x = orientation(a-start, b-start);
    if(x != 0) return x > 0;       // sort by angle
    ll d1 = dist2(start, a);
    ll d2 = dist2(start, b);
    return d1 < d2;                // if collinear, closer first
}

int main() {
    int n; 
    cin >> n;
    vector<Point> v(n);

    // read polygon A points
    for(int i=0; i<n; i++) cin >> v[i].x >> v[i].y;

    int m;
    cin >> m;

    // read polygon B points and mark them with isB=true
    for(int i=0; i<m; i++){
        int x, y; cin >> x >> y;
        v.push_back(Point(x, y, true));
    }

    int nm = n + m;

    // find the leftmost lowest point as pivot
    int first = 0;
    for(int i=1; i<nm; i++){
        if(v[i].x < v[first].x || (v[i].x == v[first].x && v[i].y < v[first].y)){
            first = i;
        }
    }

    start = v[first];
    swap(v[0], v[first]);

    // sort points by polar angle around 'start'
    sort(v.begin(), v.end(), cmp);

    // reverse collinear points at the end
    int from = nm-1;
    for(int i=nm-1; i>0; i--){
        if(orientation(v[i]-start, v[i-1]-start) != 0){
            from = i;
            break;
        }
    }
    reverse(v.begin() + from, v.end());

    // construct convex hull
    vector<Point> hull;
    for(Point p : v){
        if(hull.size() < 2){
            hull.push_back(p);
            continue;
        }
        while(hull.size() > 1){
            Point q = hull.back();
            Point r = hull[hull.size()-2];
            if(orientation(q - r, p - r) == -1) hull.pop_back(); // right turn, pop
            else break;
        }
        hull.push_back(p);
    }

    // check if any point of B is on the hull
    bool done = false;
    for(Point p : hull){
        if(p.isB){
            cout << "NO\n";
            done = true;
            break;
        }
    }

    if(!done) cout << "YES\n";
}
