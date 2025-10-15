class Solution:
    def editDistance(self, s1, s2):
        m, n = len(s1), len(s2)
        # Initialize DP table with dimensions (m+1) x (n+1)
        dp = [[0] * (n+1) for _ in range(m+1)]
        
        # Base cases: transforming from empty string
        for i in range(m+1):
            dp[i][0] = i  # Deleting all characters from s1
        for j in range(n+1):
            dp[0][j] = j  # Inserting all characters to s1 to match s2
        
        # Fill the DP table
        for i in range(1, m+1):
            for j in range(1, n+1):
                if s1[i-1] == s2[j-1]:
                    dp[i][j] = dp[i-1][j-1]  # Characters match, no operation needed
                else:
                    # Consider insert, delete, and replace operations
                    dp[i][j] = 1 + min(
                        dp[i][j-1],    # Insert
                        dp[i-1][j],    # Delete
                        dp[i-1][j-1]   # Replace
                    )
        
        return dp[m][n]
