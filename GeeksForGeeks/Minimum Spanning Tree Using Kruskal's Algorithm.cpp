class Solution
{
	public:
    // here we are using kruskal's algorithm for finding minimum spanning tree
    void makeEdgeList(vector<vector<int>> adj[],int n,vector<vector<int>>&edges){
        for(int i=0;i<n;i++){
            for(auto j:adj[i]){
                vector<int>temp;
                temp.push_back(j[1]);
                temp.push_back(j[0]);
                temp.push_back(i);
                edges.push_back(temp);
            }
        }
    }
    int findParent(vector<int>&parent,int node){
        if(parent[node]==node)return node;
        return parent[node]=findParent(parent,parent[node]);
    }
    void unionn(int u,int v,vector<int>&parent,vector<int>&rank){
        if(rank[u]<rank[v]){
            parent[u]=v;
        }
        else if(rank[u]>rank[v]){
            parent[v]=u;
        }
        else{
            parent[u]=v;
            rank[v]++;
        }
    }
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<vector<int>>edges;
        makeEdgeList(adj,V,edges);
        sort(edges.begin(),edges.end());
        vector<int>parent(V);
        vector<int>rank(V,0);
        for(int i=0;i<V;i++)parent[i]=i;
        int weight=0;
        for(int i=0;i<edges.size();i++){
            int u=findParent(parent,edges[i][1]);
            int v=findParent(parent,edges[i][2]);
            int wt=edges[i][0];
            if(u!=v){
                weight+=wt;
                unionn(u,v,parent,rank);
            }
        }
        return weight;
        
    }
};