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
private:
    vector<pair<long,long>> v;
public:
    void level(TreeNode* node, int cnt) {
        if(node == NULL)
            return;
        if(v.size() <= cnt) {
            v.push_back({node->val, 1});
        } else {
            v[cnt].first += node->val;
            v[cnt].second++;
        }
        level(node->left, cnt+1);
        level(node->right, cnt+1);
    }
    
    vector<double> averageOfLevels(TreeNode* root) {
        level(root, 0);
        vector<double> ans;
        for(int i=0; i<v.size(); i++) {
            ans.push_back(double(v[i].first) / v[i].second);
        }
        return ans;
    }
};
