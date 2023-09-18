class Node{
    public:
   int data;
   Node* left;
   Node* right;
   
   Node(int d){
       data = d;
       left = NULL;
       right = NULL;
       
       
   }
};
class cmp{
    public: 
    bool operator()(Node* a,Node* b){
        return a->data > b->data;
    }
};
class Solution
{
    public:
        void tranverse(Node* root,vector<string> &ans,string temp){
            if(root ->left == NULL && root -> right == NULL){
                ans.push_back(temp);
                return;
            }
            
            tranverse(root->left,ans,temp + '0');
            tranverse(root->right,ans,temp+ '1'); 
            
        }
        vector<string> huffmanCodes(string S,vector<int> f,int N)
        {
           priority_queue<Node*,vector<Node*>, cmp> pq;
           
           for(int i = 0;i<N;i++){
               Node* temp = new Node(f[i]);
               pq.push(temp);
           }
           
           while(pq.size() > 1){
               Node* left = pq.top();
               pq.pop();
               
               Node* right = pq.top();
               pq.pop();
               
               Node* newNode  =new Node(left->data + right->data);
               newNode -> left = left;
               newNode -> right = right;
               pq.push(newNode);
           }
           
           Node* root = pq.top();
           vector<string> ans;
           string temp = "";
           tranverse(root, ans, temp);
           return ans;
        }
};
