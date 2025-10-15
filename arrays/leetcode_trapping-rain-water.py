class Solution:
    def maxWater(self, arr):
        """
        Calculate total trapped water given elevation heights in arr.
        Uses precomputed arrays of max heights from left and right.
        """
        lmx, rmx = 0, 0
        ll, rr = [0] * len(arr), [0] * len(arr)
        # Compute max height to the left and right of each bar
        for i, j in enumerate(arr):
            lmx = max(lmx, j)
            ll[i] = lmx
            rmx = max(rmx, arr[-i-1])
            rr[-i-1] = rmx

        res = 0
        # Calculate trapped water at each position
        for i, j in enumerate(arr):
            res += min(ll[i], rr[i]) - j

        return res
