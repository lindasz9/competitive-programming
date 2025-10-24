#include <set>

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int> s;  // Set to store unique elements seen so far
        
        for (int x : nums) {
            if (s.count(x)) {  // If element already exists, duplicate found
                return true;
            }
            s.insert(x);       // Add element to the set
        }
        
        return false;  // No duplicates found after checking all elements
    }
};
