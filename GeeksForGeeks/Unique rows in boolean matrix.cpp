class Solution {
public:
    #define MAX 1000
    vector<vector<int>> uniqueRow(int M[MAX][MAX], int row, int col) {
        // Your code here
        set<pair<int,vector<int>>> s;
        for (int i = 0; i < row; i++) {
            vector<int> temp;
            for (int j = 0; j < col; j++) {
                temp.push_back(M[i][j]);
            }
            bool check=true;
            for(auto k:s){
                if(k.second==temp){check=false;break;}
            }
           if(check)s.insert(make_pair(i,temp));
        }
        vector<vector<int>> ans;
        for (auto i : s) {
            ans.push_back(i.second);
        }
        return ans;
    }
};