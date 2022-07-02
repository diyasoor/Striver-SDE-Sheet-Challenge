/************************************************************
   
   Following is the TreeNode class structure
   
   class TreeNode<T>
   { 
   public:
        T data; 
        TreeNode<T> *left;
        TreeNode<T> *right;
   
        TreeNode(T data) 
  		{ 
            this -> data = data; 
            left = NULL; 
            right = NULL; 
        }
   };
   
   
 ************************************************************/
#include<map>
TreeNode<int> *helper(vector<int> &inorder,int inStart,int inEnd, vector<int> &postorder, int poStart,int poEnd, map<int,int> &m) {
    if(poStart > poEnd || inStart > inEnd) return NULL;
    
    TreeNode<int> *root = new TreeNode<int>(postorder[poEnd]);
    
    int rootIndx = m[root->data];
    int leftCnt = rootIndx - inStart;
    root->left = helper(inorder, inStart, rootIndx-1, postorder, poStart, poStart + leftCnt -1, m);
    root->right = helper(inorder, rootIndx+1, inEnd, postorder, poStart+leftCnt, poEnd-1, m);
    return root;
}
TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postOrder, vector<int>& inOrder) 
{
	// Write your code here.
    int n = inOrder.size();
    // map <value, index> 
    map<int,int> m;
    for(int i=0;i<n;i++) {
        m[inOrder[i]] = i;
    }
    return helper(inOrder, 0, n-1, postOrder, 0, n-1, m);
}
