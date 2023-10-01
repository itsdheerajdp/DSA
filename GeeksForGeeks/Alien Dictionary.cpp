class Solution{
    public:
    void findtopo(vector<int>&topo,vector<vector<int>>adjList,vector<int>&visited,int node){
        visited[node]=1;
        for(auto i:adjList[node]){
            if(!visited[i]){
                findtopo(topo,adjList,visited,i);
            }
        }
        topo.push_back(node);
    }
    string findOrder(string dict[], int N, int K) {
        //code here
        string ans="";
        vector<vector<int>>adjList(K);
        for(int i=0;i<N-1;i++){
            string first=dict[i];
            string second=dict[i+1];
            int minlen=min(first.length(),second.length());
            for(int j=0;j<minlen;j++){
                if(first[j]!=second[j]){
                    adjList[first[j]-97].push_back(second[j]-97);
                    break;
                }
            }
        }
       vector<int>topo;
       vector<int>visited(K,0);
       for(int i=0;i<K;i++)
       if(!visited[i])
       findtopo(topo,adjList,visited,i);
       reverse(topo.begin(),topo.end());
       for(int i=0;i<topo.size();i++){
           ans+=char(topo[i]+97);
       }
       return ans;
    }
};