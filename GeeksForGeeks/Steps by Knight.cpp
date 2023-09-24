class Solution 
{
    public:
    bool isValid(int x, int y, vector<vector<bool>>& visited, int n) {
    if (x >= 1 && x <= n && y >= 1 && y <= n && visited[x][y] != true)
        return true;
    else
        return false;
}

    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    // we are using BFS traversal in this question
	    int tx=TargetPos[0];
	    int ty=TargetPos[1];
	    int sx=KnightPos[0];
	    int sy=KnightPos[1];
	    if(sx==tx && ty==sy)return 0;
	    queue<pair<int,int>>q;
	    q.push(make_pair(sx,sy));
	    int ans=0;
	    vector<vector<bool>>visited(N+1,vector<bool>(N+1,false));
	    visited[sx][sy]=true;
	    while (!q.empty()) {
            int size = q.size();
            ans++;
            while (size != 0) {
                pair<int, int> p = q.front();
                q.pop();
                int xx = p.first;
                int yy = p.second;
                int ax[8] = {1, 1, -1, -1, 2, -2, 2, -2};
                int ay[8] = {2, -2, 2, -2, 1, 1, -1, -1};
                for (int i = 0; i < 8; i++) {
                    int nx = xx + ax[i];
                    int ny = yy + ay[i];
                    if (nx == tx && ny == ty) return ans;
                    if (isValid(nx, ny, visited, N)) {
                        visited[nx][ny] = true;
                        q.push({nx, ny});
                    }
                }
                size--;
            }
	    }
	    return ans;
	}
};
