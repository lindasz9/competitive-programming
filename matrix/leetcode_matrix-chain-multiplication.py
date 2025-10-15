class Solution:
    def matrixMultiplication(self, arr):
        
        def rec(i, j):
            # Return memoized result if already computed
            if memo[i][j] != -1:
                return memo[i][j]
                
            # Base case: single matrix or no multiplication needed
            if i + 1 == j:
                return 0
            
            res = float('inf')  # Initialize min cost to infinity
            
            # Try all possible splits between i and j
            for k in range(i + 1, j):
                # Cost = left split + right split + cost of multiplying two resulting matrices
                curr = rec(i, k) + rec(k, j) + arr[i] * arr[k] * arr[j]
                res = min(res, curr)  # Track minimum cost
                
            memo[i][j] = res  # Store computed result for reuse
            return res
            
        n = len(arr)
        memo = [[-1] * n for _ in range(n)]  # Memoization table initialization
        return rec(0, n - 1)  # Compute minimum cost for full matrix chain
