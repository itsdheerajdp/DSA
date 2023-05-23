class Solution {
public:
   void solve(vector<vector<int>>&ans,vector<int> arr,vector<int>temp,int index,int target,int currentSum){
              if(currentSum==target){
                     ans.push_back(temp);
                     return;
                 }
                 if(index>=arr.size())return;//base case
                 if(currentSum>target){
                     return;//backtrack
                 }

                  //inclusion
                     currentSum+=arr[index];
                     temp.push_back(arr[index]);
                     solve(ans,arr,temp,index,target,currentSum);
                     currentSum-=arr[index];
                     temp.pop_back();

                     //exclusion
                  solve(ans,arr,temp,index+1,target,currentSum);



   }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        solve(ans,candidates,temp,0,target,0);
        return ans;
    }
};