class Solution {
  public:
    int solve(Node* root,int K,int &i){
        if(root==NULL)return -1;
        int left= solve(root->left,K,i);
        if(left!=-1)return left;
        i++;
        if(i==K)return root->data;
        int right= solve(root->right,K,i);
        if(right!=-1)return right;

    }
    // Return the Kth smallest element in the given BST
    int KthSmallestElement(Node *root, int K) {
        // add code here.
        int i=0;
        return solve(root,K,i);
    }
};