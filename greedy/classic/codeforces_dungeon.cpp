#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int main() {
	int t; cin >> t; // number of test cases
	while (t--) {
		int n, m;
		cin >> n >> m; // number of swords and monsters
		
		// min-heap to store sword damages in ascending order
		priority_queue<int, vector<int>, greater<int>> a;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			a.push(x); // insert sword damage into min-heap
		}
		
		// store monsters as pairs (life, reward)
		vector<pair<int, int>> b(m);
		for (int i = 0; i < m; i++) cin >> b[i].first;  // monster life
		for (int i = 0; i < m; i++) cin >> b[i].second; // sword reward after killing
		
		sort(b.begin(), b.end()); // sort monsters by life in ascending order
		
		int ans = 0; // count of monsters killed
		vector<int> zeros; // store monsters with zero reward temporarily
		int zeroid = 0;    // pointer to processed zero-reward monsters
		
		for (int i = 0; i < m; i++) {
			// remove swords too weak to kill current monster
			while (!a.empty() && a.top() < b[i].first) {
				if (zeroid < zeros.size()) { 
					zeroid++; // use previously stored zero-reward monsters
					ans++;    // increment kill count
				}
				a.pop(); // discard sword
			}
			if (a.empty()) break; // no sword can kill remaining monsters
			
			int sword = a.top(); // get weakest usable sword
			// special handling for last sword and zero-reward monster
			if (a.size() == 1 && !b[i].second && i < m-1) {
				zeros.push_back(b[i].first); // store zero-reward monster
				continue;
			}
			
			ans++;     // kill monster
			a.pop();   // sword used is removed
			if (b[i].second) a.push(max(sword, b[i].second)); // gain new sword if reward > 0
		}
		
		// use remaining swords to kill stored zero-reward monsters
		while (a.size()) {
			if (zeroid < zeros.size()) {
				zeroid++;
				ans++;
				a.pop();
			} else break;
		}
		
		cout << ans << '\n'; // print total monsters killed
	}
}
