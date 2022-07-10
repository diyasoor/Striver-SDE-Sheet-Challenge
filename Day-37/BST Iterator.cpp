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
// T.C = O(H)
// S.C = O(1)
class BSTiterator
{
    private: stack<TreeNode<int>*> st;
    public:
    BSTiterator(TreeNode<int> *root)
    {
        // write your code here
        pushAll(root);
    }

    int next()
    {
        // write your code here
        auto temp = st.top();
        st.pop();
        pushAll(temp->right);
        return temp->data;
    }

    bool hasNext()
    {
        // write your code here
        return !st.empty();
    }
    void pushAll(TreeNode<int>* node) {
        while(node) {
            st.push(node);
            node=node->left;
        }
    }
};


/*
    Your BSTIterator object will be instantiated and called as such:
    BSTIterator iterator(root);
    while(iterator.hasNext())
    {
       print(iterator.next());
    }
*/
