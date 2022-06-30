/************************************************************

    Following is the Binary Tree node structure:
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
bool isLeaf(TreeNode<int> *root) {
    if(!root->left && !root->right) return true;
    return false;
}
void LeftBoundary(TreeNode<int> *root,vector<int>& ans) {
    TreeNode<int> *temp = root->left;
    while(temp) {
        if(!isLeaf(temp)) ans.push_back(temp->data);
        if(temp->left) temp =temp->left;
        else temp = temp->right;
    }
} 
void RightBoundary(TreeNode<int> *root,vector<int> &ans) {
    vector<int> v;
    TreeNode<int> *temp = root->right;
    while(temp) {
        if(!isLeaf(temp)) v.push_back(temp->data);
        if(temp->right) temp =temp->right;
        else temp = temp->left;
    }
    for(int i=v.size()-1;i>=0;i--) {
        ans.push_back(v[i]);
    }
} 
// inorder Traversal
void LeafNodes(TreeNode<int> *root,vector<int> &ans) {
    if(isLeaf(root)) {
        ans.push_back(root->data);
        return;
    }
    if(root->left) LeafNodes(root->left,ans);
    if(root->right) LeafNodes(root->right,ans);
}
vector<int> traverseBoundary(TreeNode<int>* root){
    // Write your code here.
    vector<int> ans;
    if(!root) return ans;
//     if(!root->left && !root->right) return root->data};
    if(!isLeaf(root)) ans.push_back(root->data);
    LeftBoundary(root,ans);
    LeafNodes(root,ans);
    RightBoundary(root,ans);
    return ans;
}