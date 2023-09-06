class Solution {
  public:
    // Function to return the adjacency list for each vertex.
    vector<vector<int>> printGraph(int V, vector<pair<int,int>>edges) {
        // Code here
        vector<vector<int>>adjacencyList;
        for(int i=0;i<V;i++){
            vector<int>temp;
            adjacencyList.push_back(temp);
        }
        for(int i=0;i<edges.size();i++){
            adjacencyList[edges[i].first].push_back(edges[i].second);
            adjacencyList[edges[i].second].push_back(edges[i].first);
        }
        return adjacencyList;
    }
};