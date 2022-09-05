class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int ans=0,p=0,i=0,j=0;
        //maintain a p var that keeps all the set bits of current subarray
        while(j<nums.size()){
            //remove elements from starting by checking if their & is 0 with p or nor
            while((p&nums[j])!=0){
                //remove the deleted elements from beginning from p by xor
                p^=nums[i++];
            }
            p|=nums[j];
            ans = max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};