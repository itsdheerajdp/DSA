
class Solution
{
    public:
    //Function to find the vertical order traversal of Binary Tree.
    void solve(){
        
    }
    vector<int> verticalOrder(Node *root)
    {
        //Your code here
        map<int,map<int,vector<int>>>nodes;//map of horizontal distance a map of level and value of nodes
        vector<int>ans;
        if(root==NULL)return ans;
        queue<pair<Node*,pair<int,int>>>q;
        q.push(make_pair(root,make_pair(0,0)));
        while(!q.empty()){
            pair<Node*,pair<int,int>>front=q.front();
            q.pop();
            Node *nod=front.first;
            int hd=front.second.first;
            int level=front.second.second;
            nodes[hd][level].push_back(nod->data);
            if(nod->left)
            q.push(make_pair(nod->left,make_pair(hd-1,level+1)));
            if(nod->right)
            q.push(make_pair(nod->right,make_pair(hd+1,level+1)));
        }
        for(auto i:nodes){
            for(auto j:i.second){
                for(auto k:j.second) ans.push_back(k);
            }
        }
        return ans;
    }
};