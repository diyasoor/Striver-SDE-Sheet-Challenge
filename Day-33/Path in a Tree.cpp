/*   
    template <typename T = int>
	class TreeNode
	{
		public:
		T data;
		TreeNode<T> *left;
		TreeNode<T> *right;

		TreeNode(T data)
		{
			this->data = data;
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
*/

void traverse(TreeNode<int> * root, int t, vector<int> v, vector<int> &ans) {
    v.push_back(root->data);
    if(t==root->data) {
        ans=v;
        return;
    }
    if(root->left) traverse(root->left, t, v, ans);
    if(root->right) traverse(root->right, t, v, ans);
}
vector<int> pathInATree(TreeNode<int> *root, int x)
{
    // Write your code here.
    vector<int> v,ans;
    traverse(root,x,v,ans);
    return ans;
}
