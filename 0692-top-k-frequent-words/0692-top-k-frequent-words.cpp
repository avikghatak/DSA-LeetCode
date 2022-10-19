class Solution {
public:
    static bool comp(pair<string,int> a, pair<string,int> b) {
        if(a.second != b.second)
            return a.second > b.second;
        //If same frequency return in lexographic order
        return a.first < b.first;
    }
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> ans;
        unordered_map<string,int> mp;
        for(int i=0 ; i<words.size(); i++)
            mp[words[i]]++;
        vector<pair<string,int>> freq;
        for(auto it : mp)
            freq.push_back(it);
        sort(freq.begin(),freq.end(),comp);
        int i=0;
        while(i<k)
            ans.push_back(freq[i++].first);
        
        return ans;
    }
};