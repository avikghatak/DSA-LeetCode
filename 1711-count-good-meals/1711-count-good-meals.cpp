class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        unordered_map<int,int> mp;
        int ans=0;
        int mod = 1000000007;
        for(int i=0;i<deliciousness.size();i++) {
            int pow=1;
            for(int j=0;j<=21;j++){
                if(mp.find(pow-deliciousness[i])!=mp.end()){
                    ans+=mp[pow-deliciousness[i]];
                    ans = ans%mod;
                }
                pow *= 2;
            }
            mp[deliciousness[i]]++;
        }
        return ans;
    }
};