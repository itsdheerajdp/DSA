class Solution {
    
public:
    void solveDFS(pair<int,int>node,vector<vector<int>> &grid,int row,int col){
        int xx=node.first;
        int yy=node.second;
        grid[xx][yy]=0;
        int dx[]={0,0,1,-1};
        int dy[]={1,-1,0,0};
        for(int i=0;i<4;i++){
            int newx=xx+dx[i];int newy=yy+dy[i];
            if(newx>=0 && newx<row && newy>=0 && newy<col && grid[newx][newy]==1){
                solveDFS({newx,newy},grid,row,col);
            }
        }
    }
    int numberOfEnclaves(vector<vector<int>> &grid) {
     int row=grid.size();int col=grid[0].size();
     for(int i=0;i<col;i++){
         if(grid[0][i]==1){
             solveDFS({0,i},grid,row,col);
         }
         if(grid[row-1][i]==1){
             solveDFS({row-1,i},grid,row,col);
         }
     }
     for(int i=1;i<row-1;i++){
         if(grid[i][0]==1){
             solveDFS({i,0},grid,row,col);
         }
         if(grid[i][col-1]==1){
             solveDFS({i,col-1},grid,row,col);
         }
     }
     int ans=0;
     for(int i=0;i<row;i++){
         for(int j=0;j<col;j++){
             if(grid[i][j]==1)ans++;
         }
     }
     return ans;
    }
};