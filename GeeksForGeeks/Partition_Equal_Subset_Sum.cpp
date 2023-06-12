class Solution{
public:
    int solve(int arr[],int target,int size,int currSum,int index,vector<vector<int>>&dp){
        if(index>=size)return 0;
        if(target==currSum)return 1;
        else if(currSum>target)return 0;
        if(dp[index][currSum]!=-1)return dp[index][currSum];
        //include current index
        int include=solve(arr,target,size,currSum+arr[index],index+1,dp);
        //exclude current index
        int exclude=solve(arr,target,size,currSum,index+1,dp);
        return dp[index][currSum]= include or exclude;
    }
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum=0;
        for(int i=0;i<N;i++)sum+=arr[i];
        if(sum%2!=0)return 0;
        else{
            sum=sum/2;
            vector<vector<int>>dp(N+1,vector<int>(sum+1,-1));
            return solve(arr,sum,N,0,0,dp);
        }
    }
};