/************************************************************

    Following is the TreeNode class structure:

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
#include<map>
vector<int> getTopView(TreeNode<int> *root) {
    // Write your code here.
    map<int,int> m;
    vector<int> ans;
    queue<pair<TreeNode<int>*,int>> q;
    if(!root) return ans;
    q.push({root,0});
    while(!q.empty()) {
        auto v = q.front();
        q.pop();
        TreeNode<int> *temp = v.first;
        int line = v.second;
        // if line key is not present in the map then only insert it
        if(!m.count(line)) m[line] = temp->val; 
        if(temp->left) q.push({temp->left,line-1});
        if(temp->right) q.push({temp->right,line+1});
    }
    for(auto x:m) {
        ans.push_back(x.second);
    }
    return ans;
}