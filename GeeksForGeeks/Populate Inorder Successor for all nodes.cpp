class Solution
{
public:
    void inorderSolve(Node*root,Node*&prev){
        if(root==NULL)return;
        inorderSolve(root->right,prev);
        root->next=prev;
        prev=root;
        inorderSolve(root->left,prev);
    }
    void populateNext(Node *root)
    {
        //code here
        Node* prev=NULL;
         inorderSolve(root,prev);
    }
};