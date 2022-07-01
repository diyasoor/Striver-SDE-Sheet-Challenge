/**********************************************************

    Following is the Binary Tree Node structure:

    template <typename T>
    class BinaryTreeNode {
        public: 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };
***********************************************************/
#include<bits/stdc++.h>
bool isPresent(BinaryTreeNode<int> *root, int k, unordered_set<int> &s) {
    if(!root) return false;
    if(s.count(k-root->data)) return true;
    s.insert(root->data);
    return isPresent(root->left,k,s) ||
           isPresent(root->right,k,s);;
}
bool pairSumBst(BinaryTreeNode<int> *root, int k)
{
    // Write your code here
    unordered_set<int> s;
    return isPresent(root,k,s);
}