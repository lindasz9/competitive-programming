#include <bits/stdc++.h>
using namespace std;

#define int long long

int main() {
    int n, x;
    cin >> n >> x;

    string s;
    cin >> s;

    vector<char> st; // stores the effective movement sequence after cancelling opposite moves

    for(char c : s){ // if we didn't do this, it would overflow
        if(c == 'U'){
            // if last move was not U, we cancel a downward move (L or R effect)
            if(!st.empty() && st.back() != 'U') st.pop_back();
            else st.push_back('U');
        } else {
            // L or R always added to the path
            st.push_back(c);
        }
    }

    // simulate the final compressed path
    for(char c : st){
        if(c == 'U') x /= 2;        // move to parent
        else if(c == 'L') x *= 2;   // move to left child
        else x = 2 * x + 1;         // move to right child
    }

    cout << x << '\n';
}
