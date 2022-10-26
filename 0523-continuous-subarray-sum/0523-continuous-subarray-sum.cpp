class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        //pref_sum_mod,index
        unordered_map<int,int> mp;
        int sum = 0;
        /* each number can be represented as kn+x 
        where x is the remainder(that we are storing in pref array)
        if we encounter x at ind i and again x at index j 
        that means the sum from i to j is div by k 
        as sum = kn + x - (km + x) = k(m+n) */
        
        for(int i=0;i<n;i++){
            sum+=nums[i];
            int rem = sum%k;
            if(rem == 0 && i>0)
                return true;
            //return true if x already exists and the subarray size > 1
            if(mp.find(rem)!=mp.end() && (i-mp[rem]) > 1){
                    return true;
            }
            else if (mp.find(rem)==mp.end())
                mp[rem]=i;
        }
        return false;
    }
};