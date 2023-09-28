class Solution
{
    public:
    void solveDFS( vector<pair<int,int>>adj,int node,vector<int>&visited,int &end,int &minwt){
        visited[node]=1;
        if(adj[node].first!=0 && !visited[adj[node].first])
        {
            minwt=min(minwt,adj[node].second);
            end=adj[node].first;
            solveDFS(adj,adj[node].first,visited,end,minwt);
        }
        
       
    }
    vector<vector<int>> solve(int n,int p,vector<int> a,vector<int> b,vector<int> d)
    {
        
        vector<pair<int,int>>adj(n+1,{0,0});
        vector<vector<int>>ans;
        vector<int>indegree(n+1,0);
        vector<int>outdegree(n+1,0);
        for(int i=0;i<p;i++){
            indegree[b[i]]=1;
            outdegree[a[i]]=1;
            adj[a[i]]={b[i],d[i]};
        }
        vector<int>visited(n+1,0);
        for(int i=1;i<=n;i++){
        if(indegree[i]==0 && outdegree[i]==1 && !visited[i] )
        {
            int start=i;
            int end=-1;
            int minwt=INT_MAX;
            solveDFS(adj,i,visited,end,minwt);
            ans.push_back({i,end,minwt});
        }
        }
        return ans;
    }
};