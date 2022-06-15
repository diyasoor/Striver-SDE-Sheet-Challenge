vector<int> buildBoard(vector<vector<int>> board) {   
    vector<int> vec;
    for(int i=0;i<board.size();i++) {
        for(int j=0;j<board[0].size();j++) {
            vec.push_back(board[i][j]);
        }
    }
    return vec;
}
bool canPlace(vector<vector<int>> board, int n,int x,int y) {
    for(int k=0;k<x;k++) {
        if(board[k][y]==1) return false;
    }
    int i=x,j=y;
    while(i>=0 and j>=0) {
        if(board[i][j]==1) return false;
        i--;j--;
    }
    i = x, j = y;
    while(i>=0 and j<n) {
        if(board[i][j]==1) return false;
        i--; j++;
    }
    return true;
}
void utilNQueen(int n, vector<vector<int>> board, vector<vector<int>>& ans,int i) {
    // base case
    if(i==n) {
        vector<int> v;
        for(int i=0;i<board.size();i++) {
            for(int j=0;j<board[0].size();j++) {
                v.push_back(board[i][j]);
            }
        }
        ans.push_back(v);
        return;
    }
    // recursive case
    for(int j=0;j<n;j++) {
        if(canPlace(board,n,i,j)) {
            board[i][j] = 1;
            utilNQueen(n, board, ans,i+1);
            board[i][j] = 0;
        }
    }
}
vector<vector<int>> solveNQueens(int n) {
    // Write your code here.
    vector<vector<int>> ans;
    vector<vector<int>> board(n, vector<int>(n,0));
    utilNQueen(n, board, ans, 0);
    return ans;
}