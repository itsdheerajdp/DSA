class Solution {
  public:
    // Function to convert a binary tree into its mirror tree.
    void mirror(Node* node) {
        // code here
        Node *rt=node->right;
        Node* lt=node->left;
        node->right=lt;
        node->left=rt;
       if(node->left) mirror(node->left);
       if(node->right) mirror(node->right);
    }
};