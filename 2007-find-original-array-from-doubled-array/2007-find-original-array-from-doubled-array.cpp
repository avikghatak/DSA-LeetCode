class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        vector<int> original;
        unordered_map<int,int> mp;
        int n = changed.size();
        sort(changed.begin(), changed.end());
        if(n%2!=0)
            return original;
        for(int num : changed)
            mp[num]++;
        for(int num : changed){
            if(mp[num]>0 && mp[num*2]>0){
                mp[num]--;
                mp[num*2]--;
                original.push_back(num);
            }
        }
        for(auto it:mp){
            if(it.second > 0)
                return {};
        }
        return original;
    }
};