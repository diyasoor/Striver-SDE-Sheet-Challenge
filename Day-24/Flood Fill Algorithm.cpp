void dfs(vector<vector<int>> &image, int x, int y, int color,int row, int col,int src) {
    if(x<0 || y<0 || x>=row || y>=col) return;
    if(image[x][y]!=src) return;
    image[x][y] = color;
    
    dfs(image,x-1,y,color,row,col,src);   // TOP
    dfs(image,x+1,y,color,row,col,src);   // BOTTOM
    dfs(image,x,y-1,color,row,col,src);   // LEFT
    dfs(image,x,y+1,color,row,col,src);   // RIGHT
}
vector<vector<int>> floodFill(vector<vector<int>> &image, int x, int y, int newColor)
{
    // Write your code here.
    if(newColor==image[x][y]) return image;
    int row = image.size();
    int col = image[0].size();
    int src = image[x][y];
    dfs(image,x,y,newColor,row,col,src);
    return image;
}