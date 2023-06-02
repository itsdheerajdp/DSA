class Solution
{
    public:
    int solve(int n,int arr[]){
      vector<int>ans;
      ans.push_back(arr[0]);
      for(int i=1;i<n;i++){
          if(arr[i]>ans[ans.size()-1]){
              ans.push_back(arr[i]);
          }
          else{
            int index=lower_bound(ans.begin(),ans.end(),arr[i])-ans.begin();
            ans[index]=arr[i];
          }
          
      }
      return ans.size();
        
    }
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
       return solve(n,a);
    }
};