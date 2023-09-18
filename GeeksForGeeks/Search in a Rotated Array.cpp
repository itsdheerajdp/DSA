class Solution{
    public:
    int getpivot(int arr[],int l,int h){
        while(l<h){
            int mid=(l+h)/2;
            if(arr[mid]>=arr[0]){
                l=mid+1;
            }
            else {
                h=mid;
            }
        }
        return l;
    }
    int binarySearch(int arr[],int low,int high,int key){
        while(low<=high){
            int mid=(low+high)/2;
            if(arr[mid]==key)return mid;
            else if(arr[mid]>key)high=mid-1;
            else low=mid+1;
        }return -1;
    }
    int search(int A[], int l, int h, int key){
        int pivot=getpivot(A,l,h);
        if(key>=A[pivot] && key<=A[h]){
            return binarySearch(A,pivot,h,key);
        }else return binarySearch(A,l,pivot-1,key);
    }
};
