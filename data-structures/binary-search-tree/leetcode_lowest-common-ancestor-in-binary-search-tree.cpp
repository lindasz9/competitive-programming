/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Traverse the BST until the split point is found
        while (true) {
            if (root->val > p->val && root->val > q->val) {
                root = root->left;   // Both nodes are in left subtree
            } else if (root->val < p->val && root->val < q->val) {
                root = root->right;  // Both nodes are in right subtree
            } else {
                return root;         // Split point found, this is LCA
            }
        }
    }
};
