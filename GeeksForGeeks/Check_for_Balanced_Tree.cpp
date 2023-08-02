class Solution{
    public:
    //Function to check whether a binary tree is balanced or not.
    pair<bool,int> Balanced(Node *root){//pair of boolean(which tell us the node is balanced or not) and integer(which tell us the height of the node)
        if(root==NULL)
        {
            pair<bool,int>p=make_pair(true,0);
            return p;
        }
        pair<bool,int>ans;
        pair<bool,int> left=Balanced(root->left);
        pair<bool,int> right=Balanced(root->right);
        bool curr=abs(left.second-right.second)<=1;
        if(left.first & right.first & curr){
            ans.first=true;
        }else ans.first=false;
        ans.second=1+max(left.second,right.second);
        return ans;
    }
    bool isBalanced(Node *root)
    {
    
        return Balanced(root).first;
    }
};