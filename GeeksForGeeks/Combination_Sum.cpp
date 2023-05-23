class Solution {
  public:
 void solve(vector<int>arr,int target,int index,vector<vector<int>>&ans,vector<int>output){
      if(index>=arr.size()){
          return;
      }
      if(target==0){
        //   sort(output.begin(),output.end());
          ans.push_back(output);
          return;
      }
      if(target<0)return;
      output.push_back(arr[index]);
      solve(arr,target-arr[index],index,ans,output);
      output.pop_back();
      solve(arr,target,index+1,ans,output);
  }
  
    // Function to return a list of indexes denoting the required 
    // combinations whose sum is equal to given number.
    vector<vector<int> > combinationSum(vector<int> &A, int B) {
        // Your code here
        vector<vector<int>> ans;
        vector<int>output;
      sort(A.begin(),A.end());
      A.erase(unique(A.begin(),A.end()),A.end());
      solve(A,B,0,ans,output);
      
      return ans;
    }
};