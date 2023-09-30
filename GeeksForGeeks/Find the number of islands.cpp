class Solution {
  public:
    void solveDFS(vector<vector<bool>> &visited,pair<int,int>node,int row,int col,vector<vector<char>>& grid){
        int x=node.first;
        int y=node.second;
        visited[x][y]=true;
        int dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
        int dy[] = {0, 0, 1, -1, 1, -1, 1, -1};
        for(int i=0;i<8;i++){
            int newx=x+dx[i];
            int newy=y+dy[i];
            if(newx>=0 && newx<row && newy>=0 && newy<col && !visited[newx][newy] && grid[newx][newy]=='1'){
                solveDFS(visited,{newx,newy},row,col,grid);
            }
        }
    }
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int row=grid.size();
        int col=grid[0].size();
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        int ans=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(!visited[i][j] && grid[i][j]=='1'){
                    solveDFS(visited,{i,j},row,col,grid);
                       ans++;
                }
            }
        }
        return ans;
    }
};
