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
#include<bits/stdc++.h>
vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    // Write your code here!
    int flag=0;
    vector<int> ans;
    if(!root) return ans;
    vector<vector<int>> dummy;
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    
    while(!q.empty()) {
        int size = q.size();
        vector<int> v;
        for(int i=0;i<size;i++) {
            BinaryTreeNode<int> *temp = q.front();
            q.pop();
            v.push_back(temp->data);
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
        if(flag==0) {
            dummy.push_back(v);
            flag=1;
        }
        else {
            reverse(v.begin(),v.end());
            dummy.push_back(v);
            flag=0;
        }
    }
    for(int i=0;i<dummy.size();i++) {
        for(int j=0;j<dummy[i].size();j++) {
            ans.push_back(dummy[i][j]);
        }
    }
    return ans;
}
