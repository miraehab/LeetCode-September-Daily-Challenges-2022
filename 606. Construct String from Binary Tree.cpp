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
    string ans = "";
    void preOrder(TreeNode* node){
        if(node == nullptr) return;
        
        //if the first node do not put an open bracket
        if(ans.length() == 0) ans += to_string(node->val);
        else{
            ans += '(';
            ans += to_string(node->val); 
        }
        
        
        preOrder(node->left);
        
        //a  node that have a right child and no left child 
        //we put () instead of the let child
        if(node->right != nullptr && ans[ans.length()-1] != ')') ans += "()";
        
        preOrder(node->right);
        
        ans +=')';
    }
    string tree2str(TreeNode* root) {
        preOrder(root);
        ans.pop_back();
        return ans;
    }
};