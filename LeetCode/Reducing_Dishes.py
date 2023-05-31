class Solution {
public:
    int solve(vector<int>&arr,int time,int index,vector<vector<int>>&dp){
       if(index>=arr.size())return 0;
       if(dp[time][index]!=-1)return dp[time][index];
       // include this index
       int include=time*arr[index]+solve(arr,time+1,index+1,dp);
       //exclude this index
       int exclude=solve(arr,time,index+1,dp);
       dp[time][index]= max(include,exclude);
       return dp[time][index];
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        vector<vector<int>>dp(satisfaction.size()+1,vector<int>(satisfaction.size()+1,-1));
        sort(satisfaction.begin(),satisfaction.end());
        return solve(satisfaction,1,0,dp);
    }
};