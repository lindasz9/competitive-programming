#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
	    int n, k, s;
	    cin >> n >> k >> s;
	    vector<int> a(n);
	    for (int i = 0; i < n; i++) cin >> a[i];

	    int r = 0, sum = 0;
	    vector<int> end(n);

	    // two-pointer: for each left index l, find farthest r such that sum in [l, r) <= s
	    for (int l = 0; l < n; l++) {
	        while (r < n && sum + a[r] <= s) {
	            sum += a[r];
	            r++;
	        }
	        end[l] = r;    // store first index beyond valid segment
	        sum -= a[l];   // move left pointer forward
	    }

	    // compute maximum power of 2 needed for binary lifting
	    int lg = 1;
      while ((1 << lg) <= k) lg++;  
	    vector<vector<int>> up(n+1, vector<int>(lg, n));

	    // build jump table: up[i][j] = index reached after 2^j valid jumps starting from i
	    for (int i = n-1; i >= 0; i--) {
	        up[i][0] = end[i];
	        for (int j = 1; j < lg; j++)
	            up[i][j] = up[up[i][j-1]][j-1];
	    }

	    int ans = 0;
	    // try starting from every index i
	    for (int i = 0; i < n; i++) {
	        int kk = k, j = 0, ii = i;
	        // jump kk times using binary lifting to simulate dividing into ≤k subsegments
	        while (kk) {
	            if (kk & 1) ii = up[ii][j];
	            kk >>= 1;
	            j++;
	        }
	        ans = max(ans, ii - i); // update maximum length
	    }
	    cout << ans << endl;
	}
}
