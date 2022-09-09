class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> dq;
        //add first k elements in dequeue
        for(int i=0;i<k;i++){
            //remove all the elements smaller than nums[i]
            while(!dq.empty() && dq.back()<nums[i])
                dq.pop_back();
            dq.push_back(nums[i]);
        }
        ans.push_back(dq.front());
        //for the rest of the subarrays
        for(int i=k;i<nums.size();i++){
            //if the element from last subarray is present it has to be at front
            //otherwise it would have been removed already
            if(dq.front()==nums[i-k])
                dq.pop_front();
            //again remove all elements <nums[i]
            while(!dq.empty() && dq.back()<nums[i])
                dq.pop_back();
            //add the new element
            dq.push_back(nums[i]);
            ans.push_back(dq.front());
        }
        return ans;
    }
};