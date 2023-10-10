class Solution{
    public:
    int find(Node* root,int x){
        if(root==NULL)return -1;
        else if(root->data==x)return 0;
        int left=find(root->left,x);
        int right=find(root->right,x);
        if(left!=-1)return 1+left;else if(right!=-1) return 1+right;
    }
    Node *LCA(Node* root,int a,int b){
        if(root==NULL)return NULL;
        if(root->data==a || root->data==b){
            return root;
        }
        Node* left=LCA(root->left,a,b);
        Node* right=LCA(root->right,a,b);
        if(left && !right){
            return left;
        }
        else if(!left && right)return right;
        else if(left && right){
            return root;
        }
        // else return NULL;
        
        
    }
    int findDist(Node* root, int a, int b) {
        // Your code here
       Node* lca=LCA(root,a,b);
       int d1=find(lca,a);
       int d2=find(lca,b);
       if(d1!=-1 && d2!=-1)
       return d1+d2;
       else if(d1==-1)return d2;
       else return d1;
    }
};