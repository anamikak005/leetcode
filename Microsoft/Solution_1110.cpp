/*
Runtime: 7 ms
Beats: 98.43%
*/

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
    TreeNode* helper(TreeNode* root, set<int>& to_delete, vector<TreeNode*>& ans) {
        if(root == NULL) return root;
        TreeNode* right = helper(root->right, to_delete, ans);
        TreeNode* left = helper(root->left, to_delete, ans);

        if(to_delete.contains(root->val)) {
            if(right != NULL)
                ans.push_back(right);
            if(left != NULL)
                ans.push_back(left);
            return NULL;
        }
        root->right = right;
        root->left = left;
        return root;
    }
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> ans;
        set<int> del;
        for(int i = 0; i < to_delete.size(); i++)
            del.insert(to_delete[i]);
        TreeNode* r = helper(root, del, ans);
        if(r != NULL)
            ans.push_back(r);
        return ans;
    }
};