/*****************************************************

    Following is the Binary Tree node structure:
    
    class BinaryTreeNode {
        public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if(left) 
                delete left;
            if(right) 
                delete right;
        }
    };

******************************************************/

bool util(BinaryTreeNode<int>* Left, BinaryTreeNode<int>* Right) {
    if(!Left || !Right) return Left==Right;
    if(Left->data != Right->data) return false;
    return util(Left->left, Right->right) && util(Left->right, Right->left);
}
bool isSymmetric(BinaryTreeNode<int>* root)
{
    // Write your code here.    
    return !root || util(root->left, root->right);
}