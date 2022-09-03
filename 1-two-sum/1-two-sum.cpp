class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        int n = nums.size()-1,x,y;
        for(int i=0; i<n; i++)
        {
            x=nums[i];
            y=target-x;
            for(int j=i+1; j<=n; j++)
            {
                if(nums[j] == y)
                {
                    ans.push_back(i);
                    ans.push_back(j);
                    return ans;
                }
            }
        }
        return ans;
    }
};