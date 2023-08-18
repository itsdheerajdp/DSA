class Solution
{
    public:
    //Function to return a list of integers denoting the node 
    //values of both the BST in a sorted order.
    void inorder(Node*root,vector<int>&in){
        if(root==NULL)return;
        inorder(root->left,in);
        in.push_back(root->data);
        inorder(root->right,in);
    }
    void mergeSortedArray(vector<int>in1,vector<int>in2,vector<int>&ans,int ind1,int ind2){
        while(ind1<in1.size()&&ind2<in2.size()){
             if(in1[ind1]<in2[ind2]){
            ans.push_back(in1[ind1++]);
             }
              else ans.push_back(in2[ind2++]);
      }
        while(ind1<in1.size()){
            ans.push_back(in1[ind1++]);
        }
         while(ind2<in2.size()){
            ans.push_back(in2[ind2++]);
        }
       
    }
    vector<int> merge(Node *root1, Node *root2)
    {
       //Your code here
       vector<int>in1;
       vector<int>in2;
       inorder(root1,in1);
       inorder(root2,in2);
       vector<int>ans;
       int i=0,j=0;
       mergeSortedArray(in1,in2,ans,i,j);
       return ans;
    }
};