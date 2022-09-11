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

    bool DFS(TreeNode* node){
        if (node == nullptr) return false;
        
        bool leftContainsOne = DFS(node->left);
    
        bool rightContainsOne = DFS(node->right);

        if (!leftContainsOne) node->left = nullptr;
        
        if (!rightContainsOne) node->right = nullptr;
        
        return node->val == 1 || leftContainsOne || rightContainsOne;
    }
    
    
    TreeNode* pruneTree(TreeNode* root) {
        return DFS(root)? root : nullptr;
    }
};