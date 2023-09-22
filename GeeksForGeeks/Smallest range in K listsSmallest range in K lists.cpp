#include <vector>
#include <set>
#include <utility>


class Node{
    public:
    int data;
    int row;
    int column;
    Node(int a,int b,int c){
        data=a;
        row=b;
        column=c;
    }
};

class cmp{
  public:
  bool operator()(Node* a,Node* b){
      return a->data>b->data;
  }
};
class Solution {
public:
    pair<int, int> findSmallestRange(int KSortedArray[][N], int n, int k) {
    int ansEnd,ansStart;
    int maxi=INT_MIN,mini=INT_MAX;
    priority_queue<Node*,vector<Node*>,cmp>pq;
    
    for(int i=0;i<k;i++){
        int element=KSortedArray[i][0];
        maxi=max(maxi,element);
        mini=min(mini,element);
        pq.push(new Node(element,i,0));
    }
    ansStart=mini;ansEnd=maxi;
    while(true){
        Node* temp=pq.top();
        pq.pop();
        int mm=temp->data;
        if(maxi-mm < ansEnd-ansStart){
            ansEnd=maxi;
            ansStart=mm;
            maxi=ansEnd;
        }
        if(temp->column < n-1){
            int el=KSortedArray[temp->row][temp->column+1];
            pq.push(new Node(el,temp->row,temp->column+1));
            maxi=max(maxi,el);
        }
        else{
            break;
        }
        
    }
    
    return make_pair(ansStart,ansEnd);
    
    
    }
};