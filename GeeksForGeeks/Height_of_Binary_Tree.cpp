class Solution{
    public:
    //Function to find the height of a binary tree.
   
    int height(struct Node* node){
        // code here 
        if(node->left==NULL && node->right==NULL)return 1;
        else if(node->left==NULL && node->right!=NULL)return 1+height(node->right); 
        else if(node->left!=NULL && node->right==NULL)return 1+height(node->left);
        else{
            return max(1+height(node->left),1+height(node->right));
        }
    }
};