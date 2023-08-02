class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
    	// Code here
    	vector<int>ans;
    	queue<Node*>q;
    	if(root==NULL)return ans;
    	q.push(root);
    	bool leftToright=true;
    	while(!q.empty()){
    	    
    	    int levelNodesize=q.size();
    	    vector<int>LevelNodes;
    	    for(int i=0;i<levelNodesize;i++){
    	        Node *nod = q.front();
    	        q.pop();
    	        LevelNodes.push_back(nod->data);
    	        if(nod->left)q.push(nod->left);
    	        if(nod->right)q.push(nod->right);
    	    }
    	    if(!leftToright){
    	        reverse(LevelNodes.begin(),LevelNodes.end());
    	    }
    	    for(auto node:LevelNodes){
    	        ans.push_back(node);
    	    }
    	    leftToright=!leftToright;
    	}
    	return ans;
    }
};