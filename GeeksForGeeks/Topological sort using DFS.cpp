class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	void solveDFS(vector<int>&visited,stack<int>&st,vector<int>adj[],int node){
	    visited[node]=1;
	    for(auto i:adj[node]){
	        if(!visited[i]){
	            solveDFS(visited,st,adj,i);
	        }
	    }
	    st.push(node);
	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int>ans;
	    stack<int>st;
	    vector<int>visited(V,0);
	    for(int i=0;i<V;i++)
	    if(!visited[i])
	    solveDFS(visited,st,adj,i);
	    while(!st.empty()){
	        ans.push_back(st.top());
	        st.pop();
	    }
	    return ans;
	}
};