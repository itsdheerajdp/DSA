class Solution{
public:
    int minimumDays(int S, int N, int M){
        // code here
        int buyingdays=S-S/7;
        int totalfoodneeded=M*S;
        int minday;
        if(totalfoodneeded%N==0)minday=totalfoodneeded/N;
        else minday=totalfoodneeded/N+1;
        if(minday<=buyingdays)return minday;
        else return -1;
    }
};