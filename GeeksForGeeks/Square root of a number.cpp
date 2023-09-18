class Solution{
  public:
    long long int floorSqrt(long long int x) 
    {
        // Your code goes here   
        long long int ans;
        long long int start=0;
        long long int end=x;
        while(start<=end){
            long long int mid=(start+end)/2;
            if(mid*mid==x)return mid;
            else if(mid*mid>x){
                end=mid-1;
            }
            else if(mid*mid<x){
                start=mid+1;
                ans=mid;
            }
        }
        return ans;
    }
};