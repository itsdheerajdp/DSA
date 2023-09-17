class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int K)
    {
        // Write Your Code here
        int minn=0;
        int maxx=0;
        vector<int>ans;
        sort(candies,candies+N);
        //for min
        int n=N;
        for(int i=0;i<n;i++){
            minn+=candies[i];
            n=n-K;
        }
        //for max
        int x=0;
        for(int i=N-1;i>=x;i--){
            maxx+=candies[i];
            x=x+K;
        }
        ans.push_back(minn);
        ans.push_back(maxx);
        return ans;
    }
};