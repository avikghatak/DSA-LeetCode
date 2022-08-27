class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();
        
        int prefix[m+1][n+1];
        memset(prefix,0,sizeof(prefix));
        
        for(int i=1; i<=m; ++i) prefix[i][1] = prefix[i-1][1] + matrix[i-1][0];
        for(int i=1; i<=n; ++i) prefix[1][i] = prefix[1][i-1] + matrix[0][i-1];
        
        for(int i=2; i<=m; ++i){
            for(int j=2; j<=n; ++j){
                prefix[i][j] = prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1] + matrix[i-1][j-1];
            }
        }
        
        
        int ans = INT_MIN;
        for (int i = 1; i <= m; ++i) {
			for (int j = 1; j <= n; ++j) {
				for (int r = i; r <= m; ++r) {
					for (int c = j; c <= n; ++c) {
						int sum = prefix[r][c] - prefix[i-1][c] - prefix[r][j-1] + prefix[i-1][j-1];
						if (sum <= k) {
							ans = max(ans, sum);
						}
					}
				}

			}
		}

        return ans;
    }
};