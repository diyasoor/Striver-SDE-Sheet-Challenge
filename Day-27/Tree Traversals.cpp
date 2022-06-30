/************************************************************

    Following is the Binary Tree node structure:

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


************************************************************/
void inorder(BinaryTreeNode<int> *root,vector<int>&ans)
{
    if(root==NULL)
        return;
    inorder(root->left,ans);
    ans.push_back(root->data);
    inorder(root->right,ans);
    return;
}
void preorder(BinaryTreeNode<int> *root,vector<int>&ans)
{
    if(root==NULL)
        return;
    ans.push_back(root->data);
    preorder(root->left,ans);
    preorder(root->right,ans);
    return;
}
void postorder(BinaryTreeNode<int> *root,vector<int>&ans)
{
    if(root==NULL)
        return;
    postorder(root->left,ans);
    postorder(root->right,ans);
    ans.push_back(root->data);
    return;
}
vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    // Write your code here.
    vector<vector<int>> ans;
    vector<int>inOrder, preOrder, postOrder;
    inorder(root,inOrder);
    preorder(root,preOrder);
    postorder(root,postOrder);
    ans.push_back(inOrder);
    ans.push_back(preOrder);
    ans.push_back(postOrder);
    return ans;
}