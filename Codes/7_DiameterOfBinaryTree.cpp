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

    int levels(TreeNode* root){

        if(root == NULL) return 0;

        return 1 + max(levels(root->left), levels(root->right));
    }

    void maxDia(TreeNode* root, int &maxi){

        if(root == NULL) return;

        int dia = levels(root->left) + levels(root->right);
        maxi = max(maxi, dia);

        maxDia(root->left, maxi);
        maxDia(root->right, maxi);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        
        int maxi = INT_MIN;
        maxDia(root, maxi);

        return maxi;
    }
};