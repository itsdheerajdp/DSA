class Solution{
  public:
    void inorderr(struct Node* root, vector<int>&inorder){
        if(root==NULL)return;
        inorderr(root->left,inorder);
        inorder.push_back(root->data);
        inorderr(root->right,inorder);
    }
    // root : the root Node of the given BST
    // target : the target sum
    int isPairPresent(struct Node *root, int target)
    {
    //add code here.
    vector<int>inorder;
    inorderr(root,inorder);
    int i=0;
    int j=inorder.size()-1;
    while(i<j){
        if(inorder[i]+inorder[j]==target){
            return 1;
        }
        else if(inorder[i]+inorder[j]<target){
            i++;
        }
        else j--;
    }
    return 0;
    
    }
};
