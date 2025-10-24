class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> um; // Map to store numbers and their indices
        
        for (int i = 0; i < nums.size(); i++) {
            // Check if the complement (target - current number) is already in the map
            if (um.count(target - nums[i])) {
                return {um[target - nums[i]], i}; // If yes, return the two indices
            } else {
                um[nums[i]] = i; // Otherwise, store the current number and its index
            }
        }
      // every problem has a solution according to the task
    }
};
