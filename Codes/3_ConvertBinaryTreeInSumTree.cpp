class Solution {
  public:
  
    int solve (Node* root){
        
        if(root == NULL) return 0;
        
        int original_node_val = root->data;
        int child_sum = solve(root->left) + solve(root->right);
        root->data = child_sum;
        
        return original_node_val + child_sum;
        
    }
  
    
    void toSumTree(Node *node)
    {
        int sum = solve(node);
    }
};