class Solution
{
public:
    int findShortestPath(vector<vector<int>> &mat)
    {
       // code here
       int row=mat.size();
       int col=mat[0].size();
        int dx[4] = {-1,1,0,0}, dy[4] = {0,0,-1,1};
        
        for(int i=0;i<row;i++) {
            for(int j=0;j<col;j++) {
                if(mat[i][j] == 0) {
                    if(i-1>=0 && mat[i-1][j]==1)mat[i-1][j]=-1;
                    if(i+1<row && mat[i+1][j]==1)mat[i+1][j]=-1;
                    if(j-1>=0 && mat[i][j-1]==1)mat[i][j-1]=-1;
                    if(j+1<col && mat[i][j+1]==1)mat[i][j+1]=-1;
                }
            }
        }
       vector<vector<bool>>visited(row,vector<bool>(col,false));
       queue<pair<int,pair<int,int>>>q;
       for(int i=0;i<row;i++){
          if(mat[i][0]==1){
              q.push({0,{i,0}});
              visited[i][0]=true;
          }
       }
       int ans=INT_MAX;
       while(!q.empty()){
       pair<int,pair<int,int>>node=q.front();
       q.pop();
       int dist=node.first;
       int xx=node.second.first;
       int yy=node.second.second;
       int dx[]={1,-1,0,0};
       int dy[]={0,0,1,-1};
       if(yy==col-1)ans=min(ans,dist+1);
       for(int i=0;i<4;i++){
           int newx=xx+dx[i];
           int newy=yy+dy[i];
            if(newx>=0 && newx<row && newy>=0 && newy<col && mat[newx][newy]==1 && !visited[newx][newy]) {
               q.push({dist+1,{newx,newy}});
               visited[newx][newy]=true;
           }
           
       }
           
        
        
       }
       if(ans!=INT_MAX)return ans;
       else
       return -1;
    }
};