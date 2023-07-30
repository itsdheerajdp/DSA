class Solution{
  public:
    // returns the inorder successor of the Node x in BST (rooted at 'root')
    void inorder_vector(Node *root,vector<Node*>&inorder){
        if(root==NULL)return;
        inorder_vector(root->left,inorder);
        inorder.push_back(root);
        inorder_vector(root->right,inorder);
    }
    Node * inOrderSuccessor(Node *root, Node *x)
    {
        //Your code here
        vector<Node*>inorder;
        inorder_vector(root,inorder);
        
        for(int i=0;i<inorder.size()-1;i++){
            if(inorder[i]==x)return inorder[i+1];
    
        }
        return NULL;
    }
};