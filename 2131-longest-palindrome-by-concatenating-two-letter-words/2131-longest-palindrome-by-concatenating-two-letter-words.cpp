class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int> mp;
        int ans=0;
        for(string word : words){
            string rev = word;
            reverse(rev.begin(),rev.end());
            //if reverse exists and has freq>0
            if(mp.find(rev) != mp.end() && mp[rev]>0){
                ans+=4; // 2 letters of reverse string + 2 letters of word string
                mp[rev]--;
            }
            else
                mp[word]++;
        }
        //for strings with same letters eg. gg,xx,cc
        for(auto it:mp){
            if(it.first[0]==it.first[1] && it.second>0){
                ans+=2;
                break;
            }
        }
        return ans;
    } 
};