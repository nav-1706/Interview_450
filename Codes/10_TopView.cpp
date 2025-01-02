/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution {
  public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    
    void bfs(queue<pair<Node*, int>>&qu, unordered_map<int,int>&mp){
        
        while(!qu.empty()){
            
            int n = qu.size();
            for(int i=0; i<n; i++){
                
                Node* temp = qu.front().first;
                int hLevel = qu.front().second;
                qu.pop();
                
                if(mp.find(hLevel) == mp.end()){ // map me nahi mila
                    
                    mp[hLevel] = temp->data;
                }
                
                if(temp->left) qu.push({temp->left, hLevel-1});
                if(temp->right) qu.push({temp->right, hLevel+1});
            }
        }
    }
    
    vector<int> topView(Node *root) {
        
        queue<pair<Node*, int>>qu;
        qu.push({root, 0});
        
        unordered_map<int,int>mp; // {horizontal level, node value}
        
        bfs(qu, mp);
        
        vector<pair<int,int>>v; // {hLevel, node vale}
        
        for(auto p: mp){
            v.push_back({p.first, p.second});
        }
        
        sort(v.begin(), v.end());
        
        vector<int>ans;
        for(int i=0; i<v.size(); i++){
            ans.push_back(v[i].second);
        }
        
        return ans;
    }
};