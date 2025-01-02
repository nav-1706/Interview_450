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

    void invertHelper(TreeNode* root){

        if(root == NULL) return;

        TreeNode* temp = root->right;
        root->right = root->left;
        root->left = temp;

        invertHelper(root->left);
        invertHelper(root->right); 
    }

    TreeNode* invertTree(TreeNode* root) {

        invertHelper(root);
        return root;
    }
};