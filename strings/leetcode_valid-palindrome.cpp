#include <cctype>

class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0;                  // Left pointer
        int r = s.size() - 1;       // Right pointer
        
        while (l < r) {
            if (!isalnum(s[l])) {   // Skip non-alphanumeric from left
                l++;
            }
            else if (!isalnum(s[r])) {  // Skip non-alphanumeric from right
                r--;
            }
            else if (tolower(s[l]) != tolower(s[r])) {  // Compare case-insensitive
                return false;  // Characters mismatch, not a palindrome
            }
            else {
                l++; r--;  // Move both pointers inward
            }
        }
        
        return true;  // All characters matched, valid palindrome
    }
};
