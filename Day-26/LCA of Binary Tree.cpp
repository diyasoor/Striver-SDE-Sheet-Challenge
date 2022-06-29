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
TreeNode<int>* lca(TreeNode<int> *root,int x,int y) {
    if(root==NULL) return NULL;
    if(root->data==x || root->data==y) return root;
    TreeNode<int>* Left = lca(root->left,x,y);
    TreeNode<int>* Right = lca(root->right,x,y);
    
    if(!Left) return Right;
    else if(!Right) return Left;
    else return root;
}
int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{
	//    Write your code here
    return lca(root,x,y)->data; 
}