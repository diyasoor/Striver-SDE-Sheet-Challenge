#include<bits/stdc++.h>
int heightOfTheTree(vector<int>& inorder, vector<int>& levelOrder, int N){
	// Write your code here.
    // node, index
    unordered_map<int,int> map;
    // startIndex, endIndex, height 
    queue<vector<int>> q;
    int inSize = inorder.size();
    for(int i=0;i<inSize;i++) {
        map[inorder[i]] = i;
    }
    
    if(map.count(levelOrder[0])) {
        // when right subtree is not there
        if(map[levelOrder[0]] == inorder.size()-1) 
            q.push({0, inSize-2, 1});
        // when left subtree is not there
        else if(map[levelOrder[0]]==0)
            q.push({1, inSize - 1, 1});
        // root has both left and right subtree
        else {
            q.push({0, map[levelOrder[0]]-1, 1}); //left subtree
            q.push({map[levelOrder[0]]+1, inSize-1, 1}); //right subtree
        }
    }
    int j=1, height=0;
    
    while(!q.empty()) {
        auto temp = q.front();
        q.pop();
        height = max(height, temp[2]);
        if(map.count(levelOrder[j])) {
            // same index of start and end -> one node
            if(temp[0]==temp[1])
                height=max(height, temp[2]+1);
            // no right subtree, root is at end index
            else if(map[levelOrder[j]] == temp[1]) 
                q.push({temp[0], temp[1]-1, temp[2]+1});
            // no left subtree, root is at start index
            else if(map[levelOrder[j]] == temp[0]) 
                q.push({temp[0]+1, temp[1], temp[2]+1});
            // root has both left and right subtree
            else {
                q.push({temp[0], map[levelOrder[j]]-1, temp[2]+1}); //left subtree
                q.push({map[levelOrder[j]]+1, temp[1], temp[2]+1}); //right subtree
            }
        }
        j++;
    }
    return height-1;
}