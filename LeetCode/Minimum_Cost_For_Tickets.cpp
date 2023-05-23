class Solution {
public:
int solve(int n,vector<int>days,vector<int>cost,int index,vector<int>&dp){
    if(index>=n)return 0;

    if(dp[index]!=-1)return dp[index];


    //option 1 -> for one day pass 
    int option1=cost[0]+solve(n,days,cost,index+1,dp);


    //option 2 -> for seven day pass
    int i;
    for(i=index;i<n && days[i]<days[index]+7;i++,dp);
    int option2=cost[1]+solve(n,days,cost,i,dp);


    //option 3 -> for 30 day pass
    int j;
    for(j=index;j<n && days[j]<days[index]+30;j++);
    int option3=cost[2]+solve(n,days,cost,j,dp);


   dp[index]= min(option1,min(option2,option3));
   return dp[index];
}
    int mincostTickets(vector<int>& days, vector<int>& costs) {
            vector<int>dp(days.size()+1,-1);
        return solve(days.size(),days,costs,0,dp);
    }
};