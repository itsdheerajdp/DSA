class Solution{
public:
    vector<int> maxMeetings(int N,vector<int> &S,vector<int> &F){
        vector<vector<int>>meetings;
        for(int i=0;i<N;i++){
            vector<int>temp;
           temp.push_back(F[i]); temp.push_back(S[i]);temp.push_back(i+1);
            meetings.push_back(temp);}
        sort(meetings.begin(),meetings.end());  // cmp will sort this vector according to the second element (ending time) of the pair
        vector<int>ans;
        int prevEnd,currStart;
        for(int i=0;i<N;i++){
            if(i==0){
                prevEnd=meetings[i][0];
                ans.push_back(meetings[i][2]);
                continue;
            }
            currStart=meetings[i][1];
            if(currStart>prevEnd){ans.push_back(meetings[i][2]); prevEnd=meetings[i][0];}
           
            
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};