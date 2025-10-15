'''
# Node Class:
class Node:
    def __init__(self, val):
        self.data = val
        self.left = None
        self.right = None
'''

class Solution:        
    def maxPathSum(self, root):
        
        def dfs(node):
            nonlocal res
            
            if not node:
                return float('-inf')  # Base case: null nodes contribute -inf
            
            # Recursively compute max path sums from left and right subtrees
            left = dfs(node.left)
            right = dfs(node.right)
            
            # If both children exist, consider path through current node
            if left != float('-inf') and right != float('-inf'):
                res = max(res, node.data + left + right)
            # If the root only has 1 child, handle edge case
            elif node == root:
                res = max(res, node.data + max(left, right))
            
            # If both are -inf (leaf node), treat missing children as 0
            if left == float('-inf') and right == float('-inf'):
                left, right = 0, 0

            # Return the maximum gain if continuing path through this node
            return node.data + max(left, right)
        
        res = float('-inf')  # Global variable to track max path sum
        dfs(root)
        return res  # Final maximum path sum
