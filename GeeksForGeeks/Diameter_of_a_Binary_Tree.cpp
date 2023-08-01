class Solution {
  public:
    int height(Node *root){
        if(root==NULL)return 0;
        int left=height(root->left);
        int right=height(root->right);
        int ans=1+max(left,right);
        return ans;
    }
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
        // Your code here
        if(root==NULL)return 0;
        int option1=diameter(root->left);
        int option2=diameter(root->right);
        int option3=1+height(root->left)+height(root->right);
        return max(option1,max(option2,option3));
    }
}; 