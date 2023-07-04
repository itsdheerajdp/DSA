class Solution {
public:
    
    int maxProfit(vector<int>& prices) {
      int ans=0;
        int mystock=prices[0];
        for(int i=0;i<prices.size();i++){
            if(prices[i]>mystock)ans=max(ans,prices[i]-mystock);
            else mystock=prices[i];
        }
        return ans;
        
    }
};