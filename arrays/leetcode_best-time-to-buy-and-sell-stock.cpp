#include <cctype>

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0;         // Buy pointer
        int r = 1;         // Sell pointer
        int res = 0;       // Maximum profit found so far
        
        while (r < prices.size()) {
            int profit = prices[r] - prices[l];  // Potential profit
            if (profit > 0) {
                res = max(res, profit);          // Update max profit if better
            } else {
                l = r;  // If price drops, move buy pointer to current day
            }
            r++;        // Always move sell pointer forward
        }
        
        return res;  // Return maximum profit possible
    }
};
