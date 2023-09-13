class Solution{
public:
    string findLargest(int N, int S){
        // code here
        int n=N;
        string ans="";
        while(N--){
            if(S>9){
                ans+="9";
                S-=9;
            }else{
                char ch=char(S);
                ans+=ch+'0';
                S=0;
            }
        }
        int numzero=0;
        for(int i=0;i<ans.length();i++)if(ans[i]=='0')numzero++;
        if(numzero==n && n>1 || S!=0)return "-1";else return ans;
    }
};