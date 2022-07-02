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
#include<bits/stdc++.h>
TreeNode<int> *helper(vector<int> &inorder,int inStart,int inEnd, vector<int> &preorder, int preStart,int preEnd, map<int,int> &m) {
    if(preStart > preEnd || preStart<0) return NULL;
    
    TreeNode<int> *root = new TreeNode<int>(preorder[preStart]);
    
    int rootIndx = m[root->data];
    int leftCnt = preStart + rootIndx - inStart;
    root->left = helper(inorder, inStart, rootIndx-1, preorder, preStart+1, leftCnt, m);
    root->right = helper(inorder, rootIndx+1, inEnd, preorder, leftCnt+1, preEnd, m);
    return root;
}
TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
	//    Write your code here
    int n = inorder.size();
    // map <value, index> 
    map<int,int> m;
    for(int i=0;i<n;i++) {
        m[inorder[i]] = i;
    }
    return helper(inorder, 0, n-1, preorder, 0, n-1, m);
}