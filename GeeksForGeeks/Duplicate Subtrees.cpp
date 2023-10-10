string solve(Node* root, map<string,int>&temp,vector<Node*>&ans){
    if(root==NULL)return "N";
    string s=solve(root->left,temp,ans)+to_string(root->data)+solve(root->right,temp,ans);
    temp[s]++;
    if(temp[s]==2){
       ans.push_back(root);
    }
    return s;
}
vector<Node*> printAllDups(Node* root)
{
    // Code here
    vector<Node*>ans;
    map<string,int>temp;
    string t=solve(root,temp,ans);
    return ans;
}