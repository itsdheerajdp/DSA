
class Solution
{
    public:
    vector<int> topView(Node *root)
    {
        //Your code here
        
        vector<int>ans;
        if(root==NULL)return ans;
        map<int,int>nodes;
        queue<pair<Node*,int>>q;
        q.push(make_pair(root,0));
        while(!q.empty()){
            pair<Node*,int>front=q.front();
            q.pop();
            Node* frontNode=front.first;
            int hd=front.second;
            if(!nodes[hd])
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