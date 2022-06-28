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
void inorder(TreeNode<int>* root, int& k, int &ans) {
    if(!root) return;
    inorder(root->left,k,ans);
    k--;
    if(k==0) ans = root->data;
    inorder(root->right,k,ans);
}
int kthSmallest(TreeNode<int> *root, int k)
{
	//	Write the code here.
    int ans = -1;
    inorder(root,k,ans);
    return ans;
}