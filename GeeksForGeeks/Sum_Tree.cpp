class Solution
{
    public:
    pair<bool,int>solve(Node*root){
        if(root==NULL){
            pair<bool,int>p=make_pair(true,0);
            return p;
        }
        if(root->left==NULL && root->right==NULL){
            pair<bool,int>p=make_pair(true,root->data);
            return p;
        }
        pair<bool,int>leftSubTree=solve(root->left);
        pair<bool,int>rightSubTree=solve(root->right);
        bool curr=leftSubTree.second+rightSubTree.second==root->data;
        pair<bool,int>ans;
        if(leftSubTree.first && rightSubTree.first && curr){
            ans.first=true;
            ans.second=leftSubTree.second+rightSubTree.second+root->data;
        }
        else {
            ans.first=false;
            
        }
        return ans;
        
    }
    bool isSumTree(Node* root)
    {
       return solve(root).first;
    }
};