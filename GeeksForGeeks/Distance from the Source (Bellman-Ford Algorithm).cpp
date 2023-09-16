class Solution {
  public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        vector<int>distance(V,1e8);
        distance[S]=0;
        for(int i=0;i<V;i++){
            for(int j=0;j<edges.size();j++){
                int u=edges[j][0];
                int v=edges[j][1];
                int wt=edges[j][2];
                distance[v]=min(distance[u]+wt,distance[v]);
            }
        }
        
        
        // check for negative cycle
        bool flag=false;
        for(int j=0;j<edges.size();j++){
                int u=edges[j][0];
                int v=edges[j][1];
                int wt=edges[j][2];
                if(distance[u]+wt<distance[v])
                flag=true;
        }
        if(flag)return {-1};
        else return distance;
    } 
};