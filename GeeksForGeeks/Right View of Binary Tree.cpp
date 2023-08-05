class Solution
{
    public:
    void solve(Node* root,vector<int>&ans,int level){
        if(root==NULL)return;
        if(ans.size()==level)ans.push_back(root->data);
        solve(root->right,ans,level+1);
        solve(root->left,ans,level+1);
    }
    vector<int> rightView(Node *root)
    {
       // Your Code here
       vector<int>ans;
       if(root==NULL)
            return ans;
        solve(root,ans,0);
        return ans;
    }
};