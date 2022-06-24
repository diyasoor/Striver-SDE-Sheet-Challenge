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
int check(BinaryTreeNode<int>* root) {
    if(!root) return 0;
    return max(check(root->left), check(root->right)) + 1;
}
bool isBalancedBT(BinaryTreeNode<int>* root) {
    // Write your code here.
    if(!root) return true;
    int lh = check(root->left);
    int rh = check(root->right);
    
    if(abs(lh-rh) <= 1 && isBalancedBT(root->left) && isBalancedBT(root->right)) 
        return true;
    return false;
}