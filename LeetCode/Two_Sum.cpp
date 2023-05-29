#include<unordered_map>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>ans;                  
        unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++)    
        {
            int val = target-nums[i];
            if(m.find(val)!=m.end()) 
            {
                ans.push_back(m.find(val)->second);
                ans.push_back(i);
                break;
            }
            m.insert(pair<int,int>(nums[i],i)); 
        }
        return ans;
    }
};