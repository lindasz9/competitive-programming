#include <bits/stdc++.h>

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Map to group strings by their character frequency
        map<array<int, 26>, vector<string>> hm;
        
        for (string s : strs) {
            array<int, 26> freq = {0};  // Frequency array for characters a-z
            for (char c : s) {
                freq[c - 'a']++;        // Count occurrences of each character
            }
            hm[freq].push_back(s);      // Group strings with the same frequency
        }
        
        vector<vector<string>> res;
        for (auto p : hm) {
            res.push_back(p.second);    // Collect grouped anagrams into result
        }
        
        return res;
    }
};
