
class Solution {
public:
    void leftTraverse(Node* root,vector<int>&ans){
        if(root==NULL)return;
        if(root->left==NULL && root->right==NULL)return;
        ans.push_back(root->data);
        if(root->left)leftTraverse(root->left,ans);
        else leftTraverse(root->right,ans);
    }
    void leafTraverse(Node*root,vector<int>&ans){
        if(root==NULL)return;
        if(root->right==NULL && root->left==NULL)ans.push_back(root->data);
        leafTraverse(root->left,ans);
        leafTraverse(root->right,ans);
    }
    void rightTraverse(Node *root,vector<int>&ans){
        if(root==NULL)return;
        if(root->left==NULL && root->right==NULL)return;
        if(root->right)rightTraverse(root->right,ans);
        else rightTraverse(root->left,ans);
        ans.push_back(root->data);
    }
    vector <int> boundary(Node *root)
    {
        vector<int>ans;
        if(root==NULL)return ans;
        ans.push_back(root->data);
        //left boundary nodes
        leftTraverse(root->left,ans);
        //leaf nodes
        leafTraverse(root->left,ans);
        leafTraverse(root->right,ans);
        
        // right boundary nodes
        rightTraverse(root->right,ans);
        return ans;
    }
};