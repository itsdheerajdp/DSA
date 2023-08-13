class Solution {
  public:
    Node* nodeparentmapping(Node* root,map<Node*,Node*>&nodeToparent,int target){
        queue<Node*>q;
        Node*res;
        q.push(root);
        nodeToparent[root]=NULL;
        while(!q.empty()){
            Node* front=q.front();
            q.pop();
            if(front->data==target) res=front;
            if(front->left){nodeToparent[front->left]=front;q.push(front->left);}
            if(front->right){nodeToparent[front->right]=front;q.push(front->right);}
        }
        return res;
    }
    int burningTree(Node*root ,int target,Node* targetNode,map<Node*,Node*>nodeToparent,int &ans){
        map<Node*,bool>visited;
        
        visited[targetNode]=true;
        queue<Node*>q;
        q.push(targetNode);
        while(!q.empty()){
          bool flag=false;
          int size=q.size();
          for(int i=0;i<size;i++){
          Node* front=q.front();
            q.pop();
            if(front->left && !visited[front->left]){
                flag=true;
                q.push(front->left);
                visited[front->left]=true;
            }
            if(front->right && !visited[front->right]){
                flag=true;
                q.push(front->right);
                visited[front->right]=true;
            }
            if(nodeToparent[front] && !visited[nodeToparent[front]]){
                flag=true;
                q.push(nodeToparent[front]);
                visited[nodeToparent[front]]=true;
            }
          } 
            if(flag)ans++;
        }
        return ans;
    }
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        map<Node*,Node*>nodeToparent;
        Node*targetNode=nodeparentmapping(root,nodeToparent,target);
        int ans=0;
        burningTree(root,target,targetNode,nodeToparent,ans);
        return ans;
    }
};