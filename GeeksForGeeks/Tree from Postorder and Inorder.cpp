int findposition(int el,int start,int end,int in[]){
    for(int i=start;i<=end;i++)if(in[i]==el)return i;
    return -1;
}
Node* solve(int in[],int post[],int n,int &postindex,int instart,int inend){
    if(postindex<0 || instart>inend)return NULL;
    int rootelement=post[postindex];
    int position=findposition(rootelement,instart,inend,in);
    postindex--;
    Node* root=new Node(rootelement);
    root->right=solve(in,post,n,postindex,position+1,inend);
    root->left=solve(in,post,n,postindex,instart,position-1);
    return root;
}
//Function to return a tree created from postorder and inoreder traversals.
Node *buildTree(int in[], int post[], int n) {
    // Your code here
    int postindex=n-1;
    Node* ans=solve(in,post,n,postindex,0,n-1);
    return ans;
}