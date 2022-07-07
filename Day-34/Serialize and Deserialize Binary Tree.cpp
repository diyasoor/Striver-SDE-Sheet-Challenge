/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
#include<sstream>
string serializeTree(TreeNode<int> *root)
{
 //    Write your code here for serializing the tree
    if(!root) return "";
    
    string ans="";
    
    queue<TreeNode<int>*> q;
    q.push(root);
    
    while(!q.empty()) {
        auto temp = q.front();
        q.pop();
        
        if(!temp) ans += "-1 ";
        else ans += to_string(temp->data) + " ";
        
        if(temp) {
            q.push(temp->left);
            q.push(temp->right);
        }
    }
    return ans;
}

TreeNode<int>* deserializeTree(string &serialized)
{
 //    Write your code here for deserializing the tree
    if(serialized.size()==0) return NULL;
    
    stringstream ss(serialized);
    string s;
    getline(ss, s, ' ');
    TreeNode<int>* root = new TreeNode<int>(stoi(s));
    queue<TreeNode<int>*> q;
    q.push(root);
    
    while(!q.empty()) {
        TreeNode<int>* node = q.front();
        q.pop();
        
        // creating left node
        getline(ss, s, ' ');
        if(s!="-1") {
            node->left = new TreeNode<int>(stoi(s));
            q.push(node->left);
        }
        else node->left = NULL;
        
        // creating right node
        getline(ss, s, ' ');
        if(s!="-1") {
            node->right = new TreeNode<int>(stoi(s));
            q.push(node->right);
        }
        else node->right = NULL;
    }
    return root;
}



