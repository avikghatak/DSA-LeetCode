class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans={1};
        for(int i=2;i<=rowIndex+1;i++){
            vector<int> temp(i);
            temp[0]=temp[i-1]=1;
            for(int j=1;j<i-1;j++){
                temp[j]=ans[j-1]+ans[j];
            }
            ans=temp;
        }
        return ans;
    }
};