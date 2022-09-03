class Solution {
public:
    void helper(int num,int n,int k,vector<int>& ans){
        if(n==0){
            ans.push_back(num);
            return;
        }
        int lastDig = num%10;
        //next digit of num would either be +k or -k from last digit
        if(lastDig-k >= 0) helper(num*10+lastDig-k,n-1,k,ans);
        if(k>0 && lastDig+k < 10) helper(num*10+lastDig+k,n-1,k,ans);
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> ans;
        if(n==1) ans.push_back(0);
        //numbers can start from 1-9 as first digs
        for(int i=1;i<10;i++){
            helper(i,n-1,k,ans);
        }
        return ans;
    }
};