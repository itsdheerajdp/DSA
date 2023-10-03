void inorder(Node* root,vector<float>&in){
        if(root==NULL)return;
        inorder(root->left,in);
        in.push_back(root->data);
        inorder(root->right,in);
    
}
float findMedian(struct Node *root)
{
      //Code here
      vector<float>in;
      inorder(root,in);
      if(in.size()%2!=0){
          return in[in.size()/2];
      }
      else{
          return (in[in.size()/2]+in[in.size()/2-1])/2;
      }
}