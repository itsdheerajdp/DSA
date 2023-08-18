
//Function to insert string into TRIE.
void insert(struct TrieNode *root, string key)
{
    // code here
    if(key.length()==0){
        root->isLeaf=true;
        return;
    }
    int index=key[0]-'a';
    if(root->children[index]){
        insert(root->children[index],key.substr(1));
    }
    else{
        TrieNode* neww=new TrieNode();
        root->children[index]=neww;
        root=root->children[index];
        insert(root,key.substr(1));
    }
}

//Function to use TRIE data structure and search the given string.
bool search(struct TrieNode *root, string key) 
{
    // code here
    if(key.length()==0){
        if(root->isLeaf==true)return true;
        else return false;
    }
    int index=key[0]-'a';
    if(root->children[index]){
        return search(root->children[index],key.substr(1));
    }
    else{
        return false;
    }
}