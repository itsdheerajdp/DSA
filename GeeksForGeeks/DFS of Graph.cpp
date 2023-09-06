class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void dfs(int node,unordered_map<int,bool>&visited,vector<int>&ans,vector<int>adj[]){
        ans.push_back(node);
        visited[node]=true;
        for(auto i:adj[node]){
            if(!visited[i]){
                dfs(i,visited,ans,adj);
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int>ans;
        unordered_map<int,bool>visited;
        dfs(0,visited,ans,adj);
        return ans;
    }
};