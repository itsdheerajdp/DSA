class Solution 
{
    public:
    static bool cmp(Job a,Job b){
        return a.profit>b.profit;
    }
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        int jobs=0;
        int prof=0;
        sort(arr,arr+n,cmp);
        int maxdeadline=INT_MIN;
        for(int i=0;i<n;i++)maxdeadline=max(maxdeadline,arr[i].dead);
        vector<int>deadline(maxdeadline+1,-1);
        for(int i=0;i<n;i++){
            int currId=arr[i].id;
            int currdeadLine=arr[i].dead;
            int currProfit=arr[i].profit;
            for(int j=currdeadLine;j>0;j--){
                if(deadline[j]==-1){
                    prof+=currProfit;
                    deadline[j]=currId;
                    jobs++;
                    break;
                }
            }
        }
        return {jobs,prof};
        
    } 
};