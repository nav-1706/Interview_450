class Solution{
  public:
    // The given root is the root of the Binary Tree
    // Return the root of the generated BST
    
    void inorder(Node* root, vector<int>&in){
        
        if(root == NULL) return;
        
        inorder(root->left, in);
        in.push_back(root->data);
        inorder(root->right, in);
    }
    
    void correcting(Node* root, int &i, vector<int>&in){
        
        if(root == NULL) return;
        
        correcting(root->left, i, in);
        
        root->data = in[i];
        i++;
        
        correcting(root->right, i, in);
        
    }
    
    Node *binaryTreeToBST (Node *root)
    {
        vector<int>in;
        inorder(root, in);
        
        sort(in.begin(), in.end());
        
        int i = 0;
        correcting(root, i, in);
        
        return root;
    }
};