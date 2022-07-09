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
bool fillStack(TreeNode<int> *root, TreeNode<int> *leaf, stack<TreeNode<int>*> &st) {
    st.push(root);
    if(!root->left && !root->right) {
        if(root->data==leaf->data) return true;
        else {
            st.pop();
            return false;
        }
    }
    if(root->left) 
        if(fillStack(root->left,leaf,st))
            return true;
    if(root->right) 
        if(fillStack(root->right,leaf,st))
            return true;
    st.pop(); 
    return false;
}
TreeNode<int> * invertBinaryTree(TreeNode<int> *root, TreeNode<int> *leaf)
{
	// Write your code here.
    if(!root) return NULL;
    stack<TreeNode<int>*> st;
    
    bool flag = fillStack(root,leaf,st);
    TreeNode<int> *newRoot = st.top();
    st.pop();
    TreeNode<int> *parent = newRoot;
    while(!st.empty()) {
        auto temp=st.top();
        st.pop();
        if(temp->left==parent) {
            temp->left=NULL;
            parent->left=temp;
        }
        else {
            temp->right=temp->left;
            temp->left=NULL;
            parent->left=temp;
        }
        parent=temp;
    }
    return newRoot;
}
