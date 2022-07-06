/************************************************************

Following is the Binary Tree node class
    
template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};

************************************************************/
#include<bits/stdc++.h>
vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    //    Write your code here.
    vector<int> ans;
    if(!root) return ans;
    
    map<int, map<int,vector<int>>> map;
    queue<pair<TreeNode<int>*, pair<int,int>>> q;
    
    q.push(make_pair(root,make_pair(0,0)));
    
    while(!q.empty()) {
        auto temp = q.front();
        q.pop();
        TreeNode<int>* node = temp.first;
        int d = temp.second.first;
        int l = temp.second.second;
        
        map[d][l].push_back(node->data);
        if(node->left) q.push(make_pair(node->left,make_pair(d-1,l+1)));
        if(node->right) q.push(make_pair(node->right,make_pair(d+1,l+1)));
    }
    for(auto x:map) {
        for(auto y:x.second) {
            for(auto z:y.second) {
                ans.push_back(z);
            }
        }
    }
    return ans;
}