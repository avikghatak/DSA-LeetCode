class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = INT_MIN;
        int dp[m+1][n+1];
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                dp[i][j] = matrix[i-1][j-1]+dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                for(int r=i+1;r<=m;r++){
                    for(int c=j+1;c<=n;c++){
                        int curr_sum = dp[r][c] - dp[r][j] - dp[i][c] + dp[i][j];
                        if(curr_sum<=k)
                            ans = max(ans,curr_sum);
                    }
                }
            }
        }
        return ans;
    }
};