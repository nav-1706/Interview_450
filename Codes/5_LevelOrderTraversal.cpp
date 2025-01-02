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

    void BFS(queue<TreeNode*>&qu, vector<vector<int>>& finalAns){

        vector<int>levelOrder;
        while(!qu.empty()){

            int n = qu.size();
            levelOrder.clear();

            for(int i=0; i<n; i++){

                TreeNode* temp = qu.front();
                qu.pop();
                levelOrder.push_back(temp->val);

                if(temp->left != NULL) qu.push(temp->left);
                if(temp->right != NULL) qu.push(temp->right);
            }

            finalAns.push_back(levelOrder);
        }
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        
        if(root == NULL) return {};

        queue<TreeNode*>qu;
        qu.push(root);
        vector<vector<int>>finalAns;

        BFS(qu, finalAns);

        return finalAns;
    }
};