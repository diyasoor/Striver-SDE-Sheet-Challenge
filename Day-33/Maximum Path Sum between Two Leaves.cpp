/************************************************************

    Following is the Tree node structure
	
	template <typename T>
    class TreeNode 
    {
        public : 
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) 
        {
            this -> val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
#include<bits/stdc++.h>
long long int solve(TreeNode<int> *root, long long int &maxSum) {
    if(!root) return 0;
    long long int leftSum = solve(root->left,maxSum);
    long long int rightSum = solve(root->right,maxSum);
    maxSum = max(maxSum, root->val + leftSum + rightSum);
    return root->val + max(leftSum, rightSum);
}
long long int findMaxSumPath(TreeNode<int> *root)
{
    // Write your code here.
    if(!root) return -1;
    if(!root->left || !root->right) return -1;
    long long int maxSum=0;
    solve(root, maxSum);
    return maxSum;
}