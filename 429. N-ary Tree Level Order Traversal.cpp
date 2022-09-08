/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node*> q;
        vector<vector<int>> ans;
        if(root == nullptr) return ans;
        q.push(root);
        while(!q.empty()){
            vector<int> a;
            queue<Node*> tmp;
            while(!q.empty()){
                Node* cur = q.front();
                q.pop();
                a.push_back(cur->val);
                for(int i = 0; i < cur->children.size(); ++i){
                    tmp.push(cur->children[i]);
                }
            }
            q = tmp;
            ans.push_back(a);
        }
        return ans;
    }
};