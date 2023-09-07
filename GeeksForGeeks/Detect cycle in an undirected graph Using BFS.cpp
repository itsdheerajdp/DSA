class Solution {
  public:
    // Cycle Detection using BFS
    bool cycleDetectionBFS(int node,vector<bool>&visited,vector<int>&parent,vector<int> adj[]){
        parent[node]=-1;
        queue<int>q;
        q.push(node);
        visited[node]=true;
        while(!q.empty()){
            int frontNode=q.front();
            q.pop();
            for(auto neighbour:adj[frontNode]){
                if(visited[neighbour] && parent[frontNode]!=neighbour)return true;
                else if(!visited[neighbour]){
                    visited[neighbour]=true;
                    q.push(neighbour);
                    parent[neighbour]=frontNode;
                }
            }
        }
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        bool cycleDetected=false;
        vector<bool>visited(V,false);vector<int>parent(V,-1);
        for(int i=0;i<V;i++)
        if(!visited[i]){cycleDetected=cycleDetectionBFS(i,visited,parent,adj);if(cycleDetected)return cycleDetected;}
        return cycleDetected;
        
        
    }
};