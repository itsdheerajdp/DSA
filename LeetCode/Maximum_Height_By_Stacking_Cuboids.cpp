class Solution {
public:
   int solve(vector<vector<int>>& cuboids,int index,int prevIndex,vector<vector<int>>&dp){
       if(index>=cuboids.size())return 0;
       if(dp[index][prevIndex+1]!=-1)return dp[index][prevIndex+1];
       int include=0;
       if(prevIndex==-1) include=cuboids[index][2]+solve(cuboids,index+1,index,dp);
       else if(cuboids[index][0]>=cuboids[prevIndex][0] && cuboids[index][1]>=cuboids[prevIndex][1] && cuboids[index][2]>=cuboids[prevIndex][2])           include=cuboids[index][2]+solve(cuboids,index+1,index,dp);
       int exclude=solve(cuboids,index+1,prevIndex,dp);
       return dp[index][prevIndex+1]= max(include,exclude);
   }
    int maxHeight(vector<vector<int>>& cuboids) {
        vector<vector<int>>dp(cuboids.size()+1,vector<int>(cuboids.size()+1,-1));
        for(int i=0;i<cuboids.size();i++){
            sort(cuboids[i].begin(),cuboids[i].end());
        }
        sort(cuboids.begin(),cuboids.end());
       int ans=cuboids[0][2];
       return solve(cuboids,0,-1,dp);
    }
};