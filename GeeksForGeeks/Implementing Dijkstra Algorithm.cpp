class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
   vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> dist(V, INT_MAX);  
        vector<int>visited(V,0);
        dist[S]=0;
        // distance, node
        pq.push({0, S});
        
        while(!pq.empty())
        {
            int distance=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            visited[node]=1;
            for(auto i: adj[node])
            {
                int adjNode=i[0];
                int edgeWeight=i[1];
                if(!visited[adjNode]){
                    if(distance+edgeWeight < dist[adjNode])
                {
                    dist[adjNode]=distance+edgeWeight;
                    pq.push({dist[adjNode], adjNode});
                }
                }
            }
        }
        
        return dist;
    }
};