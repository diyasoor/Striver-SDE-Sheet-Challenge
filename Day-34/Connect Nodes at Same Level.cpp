/*
    ----------------- Binary Tree node class for reference -----------------

    template <typename T>
    class BinaryTreeNode {
        public : 
            T data;
            BinaryTreeNode<T> *left;
            BinaryTreeNode<T> *right;
            BinaryTreeNode<T> *next;

            BinaryTreeNode(T data) {
                this -> data = data;
                left = NULL;
                right = NULL;
                next = NULL;
            }
    };
*/
#include<bits/stdc++.h>
void connectNodes(BinaryTreeNode< int > *root) {
    // Write your code here.
    if(!root) return;
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    
    while(!q.empty()) {
        int size=q.size();
        while(size>0) {
            BinaryTreeNode<int> * temp = q.front();
            q.pop();
            temp->next=(size>1) ? q.front() : NULL;
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
            size--;
        }
    }
}