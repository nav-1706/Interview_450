/*

Very Easy Just Small observation, 

Agar minor-Diagonal(slope of +1) print karna hai to pushAllRight to Left kar do and line 132 me pushAllLeft(temp->right)

*/


class Solution {
  public:
  
    vector<int>ans;
    
    void pushAllRight(Node* root, queue<Node*>&qu){
        
        while(root != NULL){
            qu.push(root);
            root = root->right;
        }
    }
    
    void diag(queue<Node*>&qu){
        
        while(!qu.empty()){
            
            int n = qu.size();
            for(int i=0; i<n; i++){
                
                Node*temp = qu.front();
                qu.pop();
                ans.push_back(temp->data);
                
                if(temp->left != NULL){
                    
                    pushAllRight(temp->left, qu);
                }
            }
        }
    }
    
    vector<int> diagonal(Node *root) {
        
        queue<Node*>qu;
        
        pushAllRight(root, qu);
        
        diag(qu);
        
        return ans;
    }
};