class Solution {
public:
    int concatenatedBinary(int n) {
        int mod = 1e9+7;
        long long ans=0;
        int len=0;
        for(int i=1;i<=n;i++){
            //find the len of i(binary rep) 
            if((i&(i-1))==0)
                len++;
            //left shift ans and the bits of i 
            ans = ((ans<<len) + i)%mod;
        }
        return ans;
    }
};