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
    int ans = 0;
    void dfs(TreeNode* node, vector<int> tmp){
        if(node == nullptr) return;
        
        tmp[node->val]++;
        if(node->left == nullptr && node->right == nullptr){
            int odd = 0;
            for(int j = 0; j < 10; ++j){
                if(tmp[j]%2 != 0) ++odd;
            }
            if(odd <= 1) ++ans;
        }
        
        dfs(node->left, tmp);
        dfs(node->right, tmp);
        tmp[node->val]--;
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> tmp(10, 0);
        dfs(root, tmp);
        
        return ans;
    }
};