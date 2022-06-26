/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

    class TreeNode{
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        ~TreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
    };

*************************************************************/
#include<climits>
TreeNode<int>* buildBST(vector<int>& pre, int &i, int ub) {
    if(i==pre.size() || pre[i] > ub) return NULL;
    TreeNode<int>* root = new TreeNode<int>(pre[i]);
    i++;
    root->left = buildBST(pre,i,root->data);
    root->right = buildBST(pre, i, ub);
    return root;
 }
TreeNode<int>* preOrderTree(vector<int> &preOrder){
    // Write your code here.
    int i=0;
    return buildBST(preOrder, i, INT_MAX);
}