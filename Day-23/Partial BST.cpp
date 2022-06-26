/*************************************************************
 
    Following is the Binary Tree node structure

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
bool check(BinaryTreeNode<int> *root, long minVal, long maxVal) {
    if(root==NULL) return true;
    if(root->data <= maxVal && root->data >= minVal) {
        return check(root->left, minVal, root->data) && check(root->right, root->data, maxVal);
    }
    else return false;
}
bool validateBST(BinaryTreeNode<int> *root) {
    // Write your code here
    return check(root, LONG_MIN, LONG_MAX);
}