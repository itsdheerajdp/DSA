class Solution {
public:
   
    bool buddyStrings(string s, string goal) {
        if(s==goal)  return (set<char>(s.begin(),s.end())).size()<s.length();
        int n1=s.length();
        int n2=goal.length();
        if(n1!=n2)return false;
        int i=0;
        int j=n1-1;
        while(i<j && s[i]==goal[i]){
            i++;
        }
        while(j>0 && s[j]==goal[j]){
            j--;
        }
        if(i==j)return false;
        if(i<j)swap(s[i],s[j]);
        return s==goal;
    }
};