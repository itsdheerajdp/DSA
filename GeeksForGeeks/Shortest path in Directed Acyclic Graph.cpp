class Solution {
  public:
     void createAdjList(vector<vector<pair<int,int>>>&adjList, vector<vector<int>>& edges,int M){
         for(int i=0;i<M;i++){
             pair<int,int>p=make_pair(edges[i][1],edges[i][2]);
             adjList[edges[i][0]].push_back(p);
         }
     }
     void createTopoOrder(stack<int>&topoOrder,vector<vector<pair<int,int>>>&adjList,int node,vector<int>&visited){
     visited[node]=1;
     for(auto i:adjList[node]){
         if(!visited[i.first]){
             visited[i.first]=1;
             createTopoOrder(topoOrder,adjList,i.first,visited);
         }
     }
     topoOrder.push(node);
     }
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        vector<vector<pair<int,int>>>adjList(N);
        vector<int>visited(N,0);
        createAdjList(adjList,edges,M);
        stack<int>topoOrder;
        createTopoOrder(topoOrder,adjList,0,visited);
        vector<int>distance(N,INT_MAX);
        distance[0]=0;
        while(!topoOrder.empty()){
            int top=topoOrder.top();
            topoOrder.pop();
            if(distance[top]!=INT_MAX){
                for(auto i:adjList[top]){
                    distance[i.first]=min(i.second+distance[top],distance[i.first]);
                }
            }
        }
        for(int i=0;i<N;i++)if(distance[i]==INT_MAX)distance[i]=-1;
        return distance;
    }
};