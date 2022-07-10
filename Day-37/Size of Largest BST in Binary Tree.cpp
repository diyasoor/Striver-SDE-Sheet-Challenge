/************************************************************

    Following is the Binary Tree node structure
    
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
class Node {
    public:
    int maxNode, minNode, maxSize;
    Node(int minNode, int maxNode, int maxSize) {
        this->maxNode = maxNode;
        this->minNode = minNode;
        this->maxSize = maxSize;
    }
};
Node helper(TreeNode<int> *root) {
    if(!root) return Node(INT_MAX, INT_MIN, 0);
    
    // post order traversal
    auto left = helper(root->left);
    auto right = helper(root->right);
    
    // current node is greater than max in left and smaller than min in right
    // then it is a BST
    if(left.maxNode < root->data && root->data < right.minNode) {
        return Node(min(root->data, left.minNode), max(root->data, right.maxNode), left.maxSize + right.maxSize + 1);
    }
    // o/w return [-inf, inf] so that parent can't be a valid BST
    return Node(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
}
int largestBST(TreeNode<int>* root) 
{
    // Write your code here.
    return helper(root).maxSize;
}
