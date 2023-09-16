class Solution
{
	public:
    void findtopoOrder(vector<int>&visited,stack<int>&st,vector<vector<int>>& adj,int node){
        visited[node]=1;
        for(auto i:adj[node]){
            if(!visited[i]){
                findtopoOrder(visited,st,adj,i);
            }
        }
        st.push(node);
    }
    void solveDFS(vector<int>&visited,vector<vector<int>>&transpose,int node){
        visited[node]=1;
        for(auto i:transpose[node]){
            if(!visited[i]){
                solveDFS(visited,transpose,i);
            }
        }
   
    }
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        // step 1 -> Finding Topological order
        vector<int>visited(V,0);
        stack<int>st;
        for(int i=0;i<V;i++)
        if(!visited[i])
        findtopoOrder(visited,st,adj,i);
        
        // step 2 -> Finding the transpose of the graph
        vector<vector<int>>transpose(V);
        for(int i=0;i<V;i++){
            visited[i]=0;
            for(auto j:adj[i]){
                transpose[j].push_back(i);
            }
        }
        
        // last step / step 3 -> Finding the number of strongly connected components
        int ans=0;
        while(!st.empty()){
            int top=st.top();
            st.pop();
            if(!visited[top]){
                ans++;
                solveDFS(visited,transpose,top);
            }
        }
        return ans;
    }
};