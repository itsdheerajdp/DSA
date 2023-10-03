class Solution{
public:
    //Function that constructs BST from its preorder traversal.
    Node* solve(int pre[],int size,int &index,int bound){
      if(index>=size || pre[index]>bound)return NULL;
      Node* root=newNode(pre[index++]);
      root->left=solve(pre,size,index,root->data);
      root->right=solve(pre,size,index,bound);
      return root;
    }
    Node* post_order(int pre[], int size)
    {
        int index=0;
        Node* root=solve(pre,size,index,INT_MAX);
        return root;
    }
};