class Solution {
  public:
    void createadjList(vector<vector<int>>&edges,vector<vector<int>>&adjList,int m){
        for(int i=0;i<m;i++){
            adjList[edges[i][0]].push_back(edges[i][1]);
            adjList[edges[i][1]].push_back(edges[i][0]);
        }
    }
    void solveByBFS(vector<int>&visited, vector<int>&distance,vector<vector<int>>&adjList,int node){
           queue<int>q;
           q.push(node);
           visited[node]=1;
           while(!q.empty()){
               int front=q.front();
               q.pop();
               for(auto i:adjList[front]){
                   if(!visited[i]){
                       distance[i]=1+distance[front];
                       visited[i]=1;
                       q.push(i);
                   }
               }
               
           }
    }
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
        vector<vector<int>>adjList(N);
        createadjList(edges,adjList,M);
        vector<int>distance(N,0);
        vector<int>visited(N,0);
        solveByBFS(visited,distance,adjList,src);
        for(int i=0;i<N;i++)if(distance[i]==0 && i!=src)distance[i]=-1;
        return distance;
    }
};