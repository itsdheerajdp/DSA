class Solution 
{
    public:
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    int row=grid.size();
	    int col=grid[0].size();
	   queue<pair<int,int>>q;
	   vector<vector<int>>ans(row,vector<int>(col,-1));
	   for(int i=0;i<row;i++){
	       for(int j=0;j<col;j++){
	           if(grid[i][j]==1){
	               q.push({i,j});
	               ans[i][j]=0;
	           }
	       }
	   }
	   while(!q.empty()){
	       pair<int,int>front=q.front();
	       int x=front.first;
	       int y=front.second;
	       q.pop();
	       int dx[]={0,0,1,-1};
	       int dy[]={1,-1,0,0};
	       for(int i=0;i<4;i++){
	           int newx=x+dx[i];
	           int newy=y+dy[i];
	           if(newx>=0 && newx<row && newy>=0  && newy<col && ans[newx][newy]==-1){
	           ans[newx][newy]=1+ans[x][y];
	           q.push({newx,newy});
	           }
	        
	       }
	   }
	   return ans;
	}
};