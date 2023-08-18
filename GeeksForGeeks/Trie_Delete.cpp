class Solution{
  public:
  void solve(trie_node_t *&root,string str){
      if(str.length()==0){
          root->value=0;
          return;
      }
      int index=str[0]-'a';
      solve(root->children[index],str.substr(1));
     
  }
  void deleteKey(trie_node_t *root, char key[])
  {
    //Code here
    string str=key;
    solve(root,str);
  }
};