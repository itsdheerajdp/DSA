class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int>st;
        for(int i=n-1;i>=0;i--)st.push(i);
        while(st.size()>1){
            int a=st.top();
            st.pop();
            int b=st.top();
            st.pop();
            if(M[a][b]==1)st.push(b);
            else st.push(a);
        }
        int top=st.top();
        for(int i=0;i<n;i++){
            if(M[top][i]==1)return -1;
            else if(M[i][top]==0 && i!=top)return -1;
        }return top;
    }
};