class Solution {
  public:    
    // cycle Detection Using DFS
    bool cycleDetectionDFS(int node,int parentNode,vector<bool>&visited,vector<int> adj[]){
        visited[node]=true;
        for(auto i:adj[node]){
            if(!visited[i]){
                 if(cycleDetectionDFS(i,node,visited,adj))return true;
            }
            else if(visited[i] && i!=parentNode){
                return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool>visited(V,false);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(cycleDetectionDFS(i,-1,visited,adj))return true;
            }
        }
        return false;
        
    }
};