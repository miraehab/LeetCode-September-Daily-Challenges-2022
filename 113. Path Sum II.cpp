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
    vector<vector<int>> ans;
    
    void dfs(TreeNode* node, int target, int prevSum, vector<int> path){
        if(node == nullptr) return;
        
        path.push_back(node->val);
        int sum = prevSum + node->val;
        
        if(node->right == nullptr && node->left == nullptr){
            if(sum == target){
                ans.push_back(path);
            }
        }
        
        dfs(node->left, target, sum, path);
        dfs(node->right, target, sum, path);
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        dfs(root, targetSum, 0, path);
        
        return ans;
    }
};