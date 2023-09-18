class Solution
{
    public:
    static bool cmp(pair<double,Item>a,pair<double,Item>b){
        return a.first>b.first;
    }
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        vector<pair<double,Item>>info;//first int is value per unit of weight
        for(int i=0;i<n;i++)info.push_back(make_pair((1.0*arr[i].value/arr[i].weight),arr[i]));
        sort(info.begin(),info.end(),cmp);//sort in descending order according to the value per unit of weight
        double ans=0;
        for(int i=0;i<n;i++){
            if(W>info[i].second.weight){
              ans+=(double)info[i].second.value;
              W=W-info[i].second.weight;
            }else{
                ans+=(double)info[i].first*W;
                break;
            }
        }
        return ans;
    }
        
};