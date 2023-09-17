class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    static bool cmp(pair<int,int>a,pair<int,int>b){
        if(a.second==b.second)return a.first<b.first;
        else return a.second<b.second;
    }
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<pair<int,int>>meetings;
        for(int i=0;i<n;i++)meetings.push_back(make_pair(start[i],end[i]));
        sort(meetings.begin(),meetings.end(),cmp);  // cmp will sort this vector according to the second element (ending time) of the pair
        int count=0;
        int prevEnd,currStart;
        for(int i=0;i<n;i++){
            if(i==0){
                prevEnd=meetings[i].second;
                count++;
                continue;
            }
            currStart=meetings[i].first;
            if(currStart>prevEnd){count++; prevEnd=meetings[i].second;}
           
            
        }return count;
    }
};