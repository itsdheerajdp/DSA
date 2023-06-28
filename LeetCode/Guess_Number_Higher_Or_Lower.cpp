class Solution {
public:
    int guessNumber(int n) {
      int temp=guess(n);
      if(temp==0)return n;
      else if(temp==-1)return guessNumber(n-1);
      else return guessNumber(n+1);
    }
};