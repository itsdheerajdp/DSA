class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        // code here 
        string temp="";
        string ans="";
        for(int i=S.length()-1;i>=0;i--){
            if(S[i]=='.'){
            string rev = string(temp.rbegin(), temp.rend());
            ans+=rev;
            ans.push_back('.');
            temp="";
            }
            else{
                temp.push_back(S[i]);
            }
        }
        if(temp.length()!=0)ans+=string(temp.rbegin(), temp.rend());
        return ans;
    } 
};