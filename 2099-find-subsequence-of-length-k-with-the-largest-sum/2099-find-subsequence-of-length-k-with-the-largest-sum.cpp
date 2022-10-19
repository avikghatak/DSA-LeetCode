typedef pair<int,int> p;
class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> ans;
        //<num,index>
        priority_queue<p,vector<p>,greater<p>> pq;
        for(int i=0;i<nums.size();i++){
            pq.push({nums[i],i});
            if(pq.size()>k)
                pq.pop();
        }
        //<index,num>
        vector<vector<int>> order;
        while(!pq.empty()){
            order.push_back({pq.top().second,pq.top().first});
            pq.pop();
        }
        sort(order.begin(),order.end());
        for(auto it : order)
            ans.push_back(it[1]);
        return ans;
    }
};