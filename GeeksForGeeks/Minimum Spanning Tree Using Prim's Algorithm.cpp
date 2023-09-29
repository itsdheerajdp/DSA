class Solution
{
	public:
    // here we are using prim's algorithm for finding minimum spanning tree
    int spanningTree(int V, vector<vector<int>> adj[])
    {
       
       vector<bool> visited(V, false);
        vector<int> parent(V, -1);
        vector<int> dist(V, INT_MAX);
        dist[0] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();
            visited[u] = true;

            for (auto edge : adj[u]) {
                int v = edge[0];
                int weight = edge[1];

                if (!visited[v] && dist[v] > weight) {
                    parent[v] = u;
                    dist[v] = weight;
                    pq.push({dist[v], v});
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < V; i++) ans += dist[i];
        return ans;
        
    }
};