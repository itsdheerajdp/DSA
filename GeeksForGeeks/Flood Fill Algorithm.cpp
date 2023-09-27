class Solution {
public:
    void dfs(pair<int, int> node, vector<vector<int>>& image, vector<vector<int>>& ans, map<pair<int, int>, bool>& visited, int newColor,int sourceColor) {
        visited[node] = true;
        int xx = node.first;
        int yy = node.second;
        ans[xx][yy] = newColor;
        int defX[4] = {1, -1, 0, 0};
        int defY[4] = {0, 0, 1, -1};
        for (int i = 0; i < 4; i++) {
            int newX = xx + defX[i];
            int newY = yy + defY[i];
            if (!visited[{newX, newY}] && newX >= 0 && newX < image.size() && newY >= 0 && newY < image[0].size() ) {
                if(image[newX][newY] == sourceColor)dfs({newX, newY}, image, ans, visited, newColor,sourceColor);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if (image[sr][sc] == newColor) {
            return image;
        }

        vector<vector<int>> ans = image;
        map<pair<int, int>, bool> visited;
        int sourceColor=image[sr][sc];
        dfs({sr, sc}, image, ans, visited, newColor,sourceColor);
        return ans;
    }
};