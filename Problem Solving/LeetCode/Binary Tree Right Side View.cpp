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
	void rightSideViewFunc(TreeNode *root, int level, int *maxLevel, vector<int> &v) {
		if(root == NULL)
			return;
			
		if(*maxLevel < level) {
			v.push_back(root->val);
			*maxLevel = level;
		}
		
		rightSideViewFunc(root->right, level + 1, maxLevel, v);
		rightSideViewFunc(root->left, level + 1, maxLevel, v);
	}
	
    vector<int> rightSideView(TreeNode* root) {
        vector<int> v;
        int maxLevel = 0;
        rightSideViewFunc(root, 1, &maxLevel, v);
        return v;
    }
};
