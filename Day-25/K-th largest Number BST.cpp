/************************************************************
    Following is the Binary Search Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
void getN(TreeNode<int>*root,int& cnt) {
    if(!root) return;
    getN(root->left,cnt);
    cnt++;
    getN(root->right,cnt);
}
void inorder(TreeNode<int>*root, int& k, int &ans) {
    if(!root) return;
    inorder(root->left,k,ans);
    k--;
    if(k==0) ans = root->data;
    inorder(root->right,k,ans);
}
int KthLargestNumber(TreeNode<int>* root, int k) 
{
    // Write your code here.
    int cnt=0;
    getN(root,cnt);
    int ans = -1;
    int n=cnt-k+1;
    inorder(root,n,ans);
    return ans;
}
