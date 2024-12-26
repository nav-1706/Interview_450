class Solution {
  public:
  
    unordered_map<int,int>mp; // <level, node->val>
    
    void helper(queue<pair<Node*, int>>&qu){
        
        while(!qu.empty()){
            
            int n = qu.size();
            for(int i=0; i<n; i++){
                
                Node* temp = qu.front().first;
                int hLevel = qu.front().second;
                qu.pop();
                
                mp[hLevel] = temp->data;
                
                if(temp->left) qu.push({temp->left, hLevel-1});
                if(temp->right) qu.push({temp->right, hLevel+1});
            }
        }
        
    }
    
    vector<int>bottomView(Node *root) {
        
        queue<pair<Node*, int>>qu;
        qu.push({root, 0});
        
        helper(qu);
        
        vector<vector<int>>bottom_view;
        
        for(auto p: mp){
            
            bottom_view.push_back({p.first, p.second});
        }
        
        sort(bottom_view.begin(), bottom_view.end());
        
        vector<int>ans;
        
        for(auto p: bottom_view){
            ans.push_back(p[1]);
        }
        
        return ans;
    }
};