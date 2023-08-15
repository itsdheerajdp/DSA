class Solution
{
    public:
    void Nodes(Node *root,int &ans){
        if(root==NULL)return ;
        ans++;
       Nodes(root->left,ans);
       Nodes(root->right,ans);
      
    }
    int solve(Node*root ,int k,int &i){
        if(root==NULL)return -1;
        int left=solve(root->left,k,i);
        if(left!=-1)return left;
        if(i==k)return root->data;
        i++;
      
        int right= solve(root->right,k,i);
        if(right!=-1)return right;
    }
    int kthLargest(Node *root, int K)
    {
        //Your code here
        int numnodes=0,i=0;
        Nodes(root,numnodes);
        int k=numnodes-K;
        return solve(root,k,i);
    }
};