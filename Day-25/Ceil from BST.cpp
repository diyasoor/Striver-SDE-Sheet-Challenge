/************************************************************

    Following is the TreeNode class structure:

    class BinaryTreeNode {
    public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;
        
        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if (left) {
              delete left;
            }
            if (right) {
              delete right;
            }
        }
    };

************************************************************/

int findCeil(BinaryTreeNode<int> *node, int x){
    // Write your code here.
    int ans = -1;
    BinaryTreeNode<int> * temp = node;
    while(temp) {
        if(temp->data >= x) {
            ans = temp->data;
            // as we want to max our ans
            temp = temp->left;
        }
        else temp = temp->right;
    }
    return ans;
}