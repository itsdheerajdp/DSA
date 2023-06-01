class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int size=nums.size();
        if(size<4)return {};
        vector<vector<int>>ans;
        set<vector<int>>tempAns;
        for(int first=0;first<size-3;first++){
          for(int second=first+1;second<size-2;second++){
              int third=second+1;
              int last=size-1;
              while(third<last){
                  long long a=nums[first],b=nums[second],c=nums[third],d=nums[last];
                  long sum=(a + b + c + d);
                  if(sum==target){
                      tempAns.insert({nums[first],nums[second],nums[third],nums[last]});
                      third++;
                      last--;
                  }
                  else if(sum>target){
                      last--;
                  }
                  else{
                      third++;
                  }
              }
          }
        }
        for(auto iter=tempAns.begin();iter!=tempAns.end();iter++){
            ans.push_back(*iter);
        }
        return ans;
    }
};