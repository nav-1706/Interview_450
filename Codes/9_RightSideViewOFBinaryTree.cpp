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

    void BFSlevelOrder(queue<TreeNode*>&qu, vector<int>&ans){

        int lastElementOfLevel = -101;
        while(!qu.empty()){

            int n = qu.size();
            for(int i=0; i<n; i++){

                TreeNode* temp = qu.front();
                qu.pop();
                lastElementOfLevel = temp->val;

                if(temp->left != NULL) qu.push(temp->left);
                if(temp->right != NULL) qu.push(temp->right);
            }

            ans.push_back(lastElementOfLevel);
        }
    }

    vector<int> rightSideView(TreeNode* root) {
        
        if(root == NULL) return {};

        queue<TreeNode*>qu;
        qu.push(root);

        vector<int>ans;

        BFSlevelOrder(qu, ans);
        return ans;
    }
};