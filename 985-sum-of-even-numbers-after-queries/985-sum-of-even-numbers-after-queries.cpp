class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> ans;
        int evenSum=0;
        //initial sum of even elements
        for(int x : nums){
            if(x%2==0)
                evenSum+=x;
        }
        for(auto it:queries){
            if(nums[it[1]]%2==0)
                evenSum-=nums[it[1]];
            nums[it[1]]+=it[0];
            if(nums[it[1]]%2==0)
                evenSum+=nums[it[1]];
            ans.push_back(evenSum);
        }
        return ans;
    }
};