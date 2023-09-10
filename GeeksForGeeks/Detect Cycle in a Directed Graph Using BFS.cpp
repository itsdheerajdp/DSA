class Solution {
  public:
    // as we know for directed cyclic graph topological order is not possible so we are going to use this here
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int>topologicalOrder;
        vector<int>indegree(V,0);
        for(int i=0;i<V;i++){
            for(auto j:adj[i]){
                indegree[j]++;
            }
        }
        queue<int>q;
        int count=0;
        for(int i=0;i<V;i++)if(indegree[i]==0)q.push(i);
        while(!q.empty()){
            int front=q.front();
            q.pop();
            count++;
            for(auto j:adj[front]){
                indegree[j]--;
                if(indegree[j]==0)q.push(j);
            }
        }
        if(count!=V)return true;else return false;
    }
};