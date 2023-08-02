class Solution
{
    public:
    //Function to check if two trees are identical.
    bool isIdentical(Node *r1, Node *r2)
    {
        //Your Code here
        if(r1==NULL && r2==NULL)return true;
        else if(r1==NULL && r2!=NULL)return false;
        else if(r1!=NULL && r2==NULL)return false;
        if(r1->data != r2->data)return false;
        bool left=isIdentical(r1->left,r2->left);
        bool right=isIdentical(r1->right,r2->right);
        if(left & right)return true;
        else return false;
    }
};