class Solution {
public:
        static bool compare_function(vector<int>&a,vector<int>&b){
             if(a[0]==b[0])return a[1]>b[1];
             return a[0]<b[0];
        }
        int solve(vector<vector<int>>&arr){// length of LIS(longest increasing subsequence) finding function
        vector<int>ans;
        ans.push_back(arr[0][1]);
        for(int i=1;i<arr.size();i++){
            if(arr[i][1]>ans[ans.size()-1])ans.push_back(arr[i][1]);
            else{
                int index=lower_bound(ans.begin(),ans.end(),arr[i][1])-ans.begin();
                ans[index]=arr[i][1];
            }
        }
        return ans.size();
       }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end(),compare_function);//according to compare function , it will sort the 2d array according to increasing order of index 0(width) and if width will be same then decreasing order of height --> now we can apply the method of longest increasing subsequence in height 
        return solve(envelopes);
    }
};
