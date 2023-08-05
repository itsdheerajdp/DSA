class Solution {
  public:
    vector <int> bottomView(Node *root) {
        // Your Code Here
        vector<int>ans;
        if(root==NULL)
            return ans;
        map<int,int>nodes;
        queue<pair<Node*,int>>q;
        q.push(make_pair(root,0));
        while(!q.empty()){
            pair<Node*,int>front=q.front();
            q.pop();
            Node* frontNode=front.first;
            int hd=front.second;
            nodes[hd]=frontNode->data;
            if(frontNode->left)
                q.push(make_pair(frontNode->left,hd-1));
            if(frontNode->right)
                q.push(make_pair(frontNode->right,hd+1));
        }
        for(auto i:nodes){
            ans.push_back(i.second);
        }
        return ans;
    }
};