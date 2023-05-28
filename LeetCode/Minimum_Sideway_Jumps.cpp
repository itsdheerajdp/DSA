class Solution {
public:
    int solveRecursive(vector<int>&arr,int i,int froglane){
        if(i==arr.size()-1)return 0;
        if(arr[i+1]==0)return solveRecursive(arr,i+1,froglane);
        if(arr[i+1]==froglane){
            int temp=INT_MAX;
            for(int j=1;j<=3;j++){
               if(arr[i]!=j && froglane!=j)temp=min(temp,1+solveRecursive(arr,i,j));
            }
            return temp;
        }
        else{
           return  solveRecursive(arr,i+1,froglane);
        }
       
    }
      int solveMem(vector<int>&arr,int i,int froglane,vector<vector<int>>&dp){
        if(i==arr.size()-1)return 0;
        if(dp[i][froglane]!=-1)return dp[i][froglane];
        if(arr[i+1]==0)return solveMem(arr,i+1,froglane,dp);
        if(arr[i+1]==froglane){
            int temp=INT_MAX;
            for(int j=1;j<=3;j++){
               if(arr[i]!=j && froglane!=j)temp=min(temp,1+solveMem(arr,i,j,dp));
            }
            return dp[i][froglane]=temp;
        }
        else{
           return solveMem(arr,i+1,froglane,dp);
        }
       
    }
    int minSideJumps(vector<int>& obstacles) {
        int lane=2;
        // return solveRecursive(obstacles,0,lane);
        vector<vector<int>>dp(obstacles.size()+1,vector<int>(4,-1));
        return solveMem(obstacles,0,lane,dp);
    }
};