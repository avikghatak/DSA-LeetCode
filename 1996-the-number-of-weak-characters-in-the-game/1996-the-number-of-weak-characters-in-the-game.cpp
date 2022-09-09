class Solution {
public:
    static bool myCmp(vector<int>& a,vector<int>& b){
        if(a[0]==b[0])
            return a[1]>b[1];
        return a[0]<b[0];
    }
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(),properties.end(),myCmp);
        int ans=0, maxDef = properties[properties.size()-1][1];
        for(int i=properties.size()-2;i>=0;i--){
            if(properties[i][1]<maxDef)
                ans++;
            maxDef = max(maxDef,properties[i][1]);
        }
        return ans;
    }
};