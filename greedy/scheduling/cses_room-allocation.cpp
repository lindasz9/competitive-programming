#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;

int main() {
    int n;
    cin >> n;

    vector<array<int,3>> a(n); // {arrival, departure, original index}
    for(int i=0;i<n;i++){
        cin >> a[i][0] >> a[i][1];
        a[i][2] = i; // store original order
    }

    // sort customers by arrival day
    sort(a.begin(), a.end());

    vector<int> ans(n); // room assignment for each customer

    // set of pairs {end_day, room_number}, keeps track of rooms and when they become free
    set<pii> s;

    int id = 1; // next room number
    s.insert({0, id++}); // dummy initial room

    for(auto [start, end, idx]: a){
        auto [available_day, room] = *s.begin(); // earliest available room
        if(available_day < start){
            // room is free before customer arrives
            s.erase(s.begin());
            s.insert({end, room}); // update room's new free time
            ans[idx] = room;       // assign this room
        } else {
            // no existing room free, allocate new room
            s.insert({end, id});
            ans[idx] = id;
            id++;
        }
    }

    cout << id - 1 << '\n'; // total rooms used
    for(int x: ans) cout << x << ' '; // room assignment in input order
    cout << '\n';
}
