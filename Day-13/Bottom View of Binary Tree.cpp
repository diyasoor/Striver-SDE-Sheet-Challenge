/*************************************************************
 
    Following is the Binary Tree node structure.

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
vector<int> bottomView(BinaryTreeNode<int> * root){
    // Write your code here.
    // map<line_num, node->data>
    map<int,int> m;
    vector<int> ans;
    queue<pair<BinaryTreeNode<int>*,int>> q;
    if(!root) return ans;
    q.push({root,0});
    while(!q.empty()) {
        auto v = q.front();
        q.pop();
        BinaryTreeNode<int>* temp = v.first;
        int line = v.second;
        m[line] = temp->data;
        if(temp->left) q.push({temp->left,line-1});
        if(temp->right) q.push({temp->right,line+1});
    }
    for(auto x:m) {
        ans.push_back(x.second);
    }
    return ans;
    
}
