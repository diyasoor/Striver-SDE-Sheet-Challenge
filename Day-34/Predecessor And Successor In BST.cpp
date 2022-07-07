/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

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

        ~BinaryTreeNode() {
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
    };

*************************************************************/
void inorderPredecessor(BinaryTreeNode<int>* root, int key, int& pred) {
    while(root) {
        if(root->data < key) {
            pred=root->data;
            root=root->right;
        }
        else root=root->left;
    }
}
void inorderSuccessor(BinaryTreeNode<int>* root, int key, int& succ) {
    while(root) {
        if(root->data > key) {
            succ=root->data;
            root=root->left;
        }
        else root=root->right;
    }
}
pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key) {
    // Write your code here.
    int predecessor = -1;
    int successor = -1;
    
    inorderPredecessor(root,key,predecessor);
    inorderSuccessor(root,key,successor);
    
    pair<int,int> ans= {predecessor,successor};
    return ans;
    
}
