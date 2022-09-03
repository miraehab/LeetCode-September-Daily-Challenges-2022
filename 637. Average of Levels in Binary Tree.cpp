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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> q;
        vector<double> ans;
        q.push(root);
        while(!q.empty()){
            queue<TreeNode*> tmp;
            double cnt = 0, sum = 0;
            while(!q.empty()){
                sum+=q.front()->val;
                if(q.front()->left != nullptr) tmp.push(q.front()->left);
                if(q.front()->right != nullptr) tmp.push(q.front()->right);
                q.pop();
                ++cnt;
            }
            ans.push_back(sum/cnt);
            q = tmp;
        }
        return ans;
    }
};