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
int getMaxWidth(TreeNode<int> *root)
{
    // Write your code here.
    if(!root) return 0;
    queue<TreeNode<int>*> q;
    q.push(root);
    int max_size=0;
    while(!q.empty()) {
        int size = q.size();
        max_size = max(max_size,size);
        for(int i=0;i<size;i++) {
            TreeNode<int> *temp = q.front();
            q.pop();
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
    }
    return max_size;
}