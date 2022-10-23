class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> freq(n+1,0);
        vector<int> ans;
        for(int i : nums)
            freq[i]++;
        for(int i=1;i<=n;i++){
            if(freq[i]>1)
                ans.push_back(i);
        }
        for(int i=1;i<=n;i++){
            if(freq[i]<1)
                ans.push_back(i);
        }
        return ans;
    }
};