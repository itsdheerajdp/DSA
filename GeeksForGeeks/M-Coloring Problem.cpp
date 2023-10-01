class Solution{
public:
    bool isSafe(int node,bool graph[101][101],int m,int n,int clr,vector<int>&color){
        for(int i=0;i<n;i++){
            if(graph[node][i]){
                int nbr=i;
                if(color[nbr]==clr)return false;
            }
        }
        return true;
    }
    bool solveDFS(vector<int>&color,bool graph[101][101],int m,int n,int node){
        if(node==n)return true;
        for(int j=1;j<=m;j++){
            if(isSafe(node,graph,m,n,j,color)){
                color[node]=j;
                if(solveDFS(color,graph,m,n,node+1))return true;
                color[node]=0;
            }
        }
        
        return false;
    }
    bool graphColoring(bool graph[101][101], int m, int n) {
         vector<int>color(n,0);
         if(solveDFS(color,graph,m,n,0))return true;
         else return false;
    }
};
