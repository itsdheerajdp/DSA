class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool checkCycleDFS(vector<int>&visited,vector<int>&dfsvisited,vector<int>adj[],int node){
        visited[node]=1;
        dfsvisited[node]=1;
        for(auto i:adj[node]){
            if(!visited[i]){
                bool check=checkCycleDFS(visited,dfsvisited,adj,i);
                if(check)return true;
                
            }else if(dfsvisited[i])return true;
        }
        dfsvisited[node]=false;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int>dfsvisited(V,0);
        vector<int>visited(V,0);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(checkCycleDFS(visited,dfsvisited,adj,i))return true;
            }
        }return false;
    }
};