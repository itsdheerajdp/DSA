class Solution
{
    public:
    Node* solve(Node *root,int n1,int n2){
        if(root==NULL)return NULL;
        if(root->data==n1 || root->data==n2)return root;

        Node* leftAns=solve(root->left,n1,n2);
        Node* rightAns=solve(root->right,n1,n2);
        
        if(leftAns!=NULL && rightAns!=NULL){
            return root;
        }
        else if(leftAns && !rightAns){
            return leftAns;
            
        }else if(!leftAns && rightAns)return rightAns;
        else return NULL;
    }
    //Function to return the lowest common ancestor in a Binary Tree.
    Node* lca(Node* root ,int n1 ,int n2 )
    {
       //Your code here
       Node* ans;
       ans=solve(root,n1,n2);
       return ans;
    }
};
