#include <unordered_map>

class Solution {
public:
    bool isAnagram(string s, string t) {
        // If lengths differ, strings cannot be anagrams
        if (s.size() != t.size()) {
            return false;
        }
        
        unordered_map<char, int> ss;  // Frequency map for string s
        unordered_map<char, int> tt;  // Frequency map for string t
        
        // Count characters in both strings
        for (int i = 0; i < s.size(); i++) {
            ss[s[i]]++;
            tt[t[i]]++;
        }
        
        // Compare frequency maps to determine if anagrams
        return ss == tt;
    }
};
