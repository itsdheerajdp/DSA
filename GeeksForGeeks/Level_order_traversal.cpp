class Solution
{
    public:
    //Function to return the level order traversal of a tree.
    vector<int> levelOrder(Node* node)
    {
      //Your code here
      queue<Node*>q;
      q.push(node);
      vector<int>ans;
      while(!q.empty()){
          Node *nod=q.front();
          ans.push_back(nod->data);
          q.pop();
          if(nod->left){
              q.push(nod->left);
          }
          if(nod->right)q.push(nod->right);
      }
      return ans;
    }
};