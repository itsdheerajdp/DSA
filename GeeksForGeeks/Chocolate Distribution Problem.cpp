class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
    //code
    sort(a.begin(),a.end());
    int i=0;
    int j=m-1;
    int mini=1e9;
    while(j<n)
    {
        if(a[j]-a[i]<mini)
        mini=a[j]-a[i];
        i++;
        j++;
    }
    
    return mini;
}
};