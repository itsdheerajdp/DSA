class Solution {
public:
    int solve(vector<int>&arr,int index,int n,int endIndex, vector<vector<int>>&dp){
       if(index>endIndex || n==0)return 0;
       if(dp[index][n]!=-1)return dp[index][n];
       int include=arr[index]+solve(arr,index+2,n-1,endIndex,dp);
       int exclude=solve(arr,index+1,n,endIndex,dp);
       return dp[index][n]= max(include,exclude);
    }
    int maxSizeSlices(vector<int>& slices) {
    vector<vector<int>>dp1(slices.size()+1,vector<int>(slices.size()+1,-1));
    int case1=solve(slices,0,slices.size()/3,slices.size()-2,dp1);
    vector<vector<int>>dp2(slices.size()+1,vector<int>(slices.size()+1,-1));
    int case2=solve(slices,1,slices.size()/3,slices.size()-1,dp2);
    return max(case1,case2);
    }
};