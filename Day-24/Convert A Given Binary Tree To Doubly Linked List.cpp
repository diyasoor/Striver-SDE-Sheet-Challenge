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
void convert(BinaryTreeNode<int>* root, BinaryTreeNode<int>* &head, BinaryTreeNode<int>* &prev) {
    // inorder traversal
    if(!root) return;
    convert(root->left, head, prev);
    if(prev==NULL) head=root, prev=root;
    else {
        prev->right = root;
        prev->right->left = prev;
        prev = prev->right;
    }
    convert(root->right, head, prev);
}
BinaryTreeNode<int>* BTtoDLL(BinaryTreeNode<int>* root) {
    // Write your code here
    BinaryTreeNode<int>* head = NULL, *prev = NULL;
    convert(root,head,prev);
    return head;
}