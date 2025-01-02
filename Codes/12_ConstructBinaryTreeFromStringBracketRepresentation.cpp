//User function Template for C++

/*
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};
*/


class Solution{
public:
    // function to construct tree from string
    Node *treeFromString(string str){
        
        if(str.length() == 1){
            Node* root = new Node(str[0]-'0');
            return root;
        }
        
        stack<pair<string, pair<Node*, bool>>>st;
        
        int i = 0;
        while(i < str.size()){
            
            if(str[i] != ')'){ // either number or '('
                
                if(str[i] == '('){
                    st.push({"(", {NULL, false}});
                    i++;
                }
                
                else{
                    
                    string number = "";   
                    while(isdigit(str[i])){
                        
                        number += str[i];
                        i++;
                    }
                    
                    int num = stoi(number);
                    Node* node = new Node(num);
                    st.push({number,{node, false}});
                }
            }
            
            else{
                
                Node* child = NULL;
                
                if(st.top().first != "("){ // if child node exist
                    child = st.top().second.first;
                    st.pop(); // child node delete
                }
                st.pop(); // '(' delete
                
                Node* parent = st.top().second.first;
                if(st.top().second.second == false){
                    parent->left = child;
                    st.top().second.second = true;
                }
                else parent->right = child;
                
                i++;
            }
        }
        
        return st.top().second.first;
    }
};