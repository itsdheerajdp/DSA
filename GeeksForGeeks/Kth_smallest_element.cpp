class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
        if(l==0 && r==0)return arr[0];
        //code here
        priority_queue<int,vector<int>,greater<int>>minHeap;
        for(int i=l;i<=r;i++)minHeap.push(arr[i]);
        for(int i=1;i<k;i++){
            minHeap.pop();
        }
        return minHeap.top();
        
    }
};