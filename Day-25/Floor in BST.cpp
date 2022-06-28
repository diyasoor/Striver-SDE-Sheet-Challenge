/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

int floorInBST(TreeNode<int> * root, int X)
{
    // Write your code here.
    int ans = -1;
    TreeNode<int> * temp = root;
    while(temp) {
        if(temp->val <= X) {
            ans = temp->val;
            // as we want to max our ans
            temp = temp->right;
        }
        else temp = temp->left;
    }
    return ans;
}