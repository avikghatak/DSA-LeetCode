class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int> freq,mp;
        for(int num:nums) {
            freq[num]++;
        }
        for(int num:nums) {
            if(freq[num]==0)
                continue;
            freq[num]--;
            if(mp[num-1]>0){
                mp[num-1]--;
                mp[num]++;
            }
            else if(freq[num+1]>0 && freq[num+2]>0){
                freq[num+1]--;
                freq[num+2]--;
                mp[num+2]++;
            }
        
            else
                return false;
        }
        return true;
    }
};