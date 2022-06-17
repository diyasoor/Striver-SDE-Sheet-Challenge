bool isSafe(int matrix[9][9],int r,int c,int num) {
    for(int i=0;i<9;i++) {
        if(matrix[r][i]==num || matrix[i][c]==num) return false;
        if(matrix[3 * (r/3) + (i/3)][3 * (c/3) + (i%3)]==num) return false;
    }
    return true;
}
bool isItSudoku(int matrix[9][9]) {
    // Write your code here.
    for(int i=0;i<9;i++) {
        for(int j=0;j<9;j++) {
            if(matrix[i][j]==0) {
                for(int c=1;c<=9;c++) {
                    if(isSafe(matrix,i,j,c)) {
                        matrix[i][j] = c;
                        if(isItSudoku(matrix)==true) 
                            return true;
                        else 
                            matrix[i][j] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}
