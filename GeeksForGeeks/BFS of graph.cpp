
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    void bfs(map<int,bool>&visited,   vector<int>&ans,vector<int>adj[],int node){
        queue<int>q;
        q.push(node);
        visited[node]=true;
        while(!q.empty()){
            int frontNode=q.front();
            ans.push_back(frontNode);
            q.pop();
            for(auto i:adj[frontNode]){
                if(!visited[i]){
                    q.push(i);
                    visited[i]=true;
                }
            }
        }
    }
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int>ans;
        map<int,bool>visited;
        bfs(visited,ans,adj,0);
        return ans;
    }
};