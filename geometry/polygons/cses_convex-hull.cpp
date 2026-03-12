#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Point{
    ll x,y;
    Point(ll xx=0,ll yy=0):x(xx),y(yy){}
    Point operator-(const Point& p)const{
        return Point(x-p.x,y-p.y);
    }
};

Point start;

// orientation of vectors a and b (sign of cross product)
// returns:
//  1  -> left turn
// -1  -> right turn
//  0  -> collinear
ll orientation(Point a,Point b){
    ll s = a.y*b.x - a.x*b.y;
    return (s>0) - (s<0);
}

// squared distance between two points
ll dist2(Point a,Point b){
    Point c = a-b;
    return c.x*c.x + c.y*c.y;
}

// sorting comparator by polar angle around 'start'
bool cmp(Point a,Point b){
    ll x = orientation(a-start,b-start);
    if(x!=0) return x>0;   // sort by angle
    ll d1 = dist2(start,a);
    ll d2 = dist2(start,b);
    return d1 < d2;        // if collinear, closer first
}

int main() {
    int n;
    cin>>n;

    vector<Point> v(n);
    for(int i=0;i<n;i++) cin>>v[i].x>>v[i].y;

    // find the leftmost (and lowest) point
    int first=0;
    for(int i=1;i<n;i++){
        if(v[i].x<v[first].x||(v[i].x==v[first].x&&v[i].y<v[first].y)){
            first=i;
        }
    }

    start=v[first];
    swap(v[0], v[first]);

    // sort points by polar angle
    sort(v.begin(),v.end(),cmp);

    // handle collinear points at the end
    int from=n-1;
    for(int i=n-1;i>0;i--){
        if(orientation(v[i]-start,v[i-1]-start)!=0){
            from=i;
            break;
        }
    }
    reverse(v.begin()+from,v.end());

    vector<Point> hull;

    for(Point p:v){
        if(hull.size()<2){
            hull.push_back(p);
            continue;
        }

        // maintain convex hull property
        while(hull.size()>1){
            Point q=hull[hull.size()-1];
            Point r=hull[hull.size()-2];
            if(orientation(q-r,p-r)==-1) hull.pop_back();
            else break;
        }

        hull.push_back(p);
    }

    cout<<hull.size()<<'\n';
    for(Point p:hull) cout<<p.x<<' '<<p.y<<'\n';
}
