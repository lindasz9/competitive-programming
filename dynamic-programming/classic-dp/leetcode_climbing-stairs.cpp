int step(int x) {
    // Base case: if there are 2 steps, there are 2 ways (1+1, 2)
    if (x == 2) {
        return 2;
    } 
    // Base case: if there is 1 step, only 1 way
    else if (x == 1) {
        return 1;
    }
    // Recursive case: number of ways = ways(n-1) + ways(n-2)
    return step(x-1) + step(x-2);
}

class Solution {
public:
    int climbStairs(int n) {
        // Uses recursion to calculate number of ways to climb n steps
        return step(n);
    }
};
