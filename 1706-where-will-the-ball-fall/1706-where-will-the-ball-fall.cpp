class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size(), n=grid[0].size();
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            int ind = i;
            for(int j=0;j<m;j++){
                if((ind<n-1 && grid[j][ind]==1 && grid[j][ind+1]==-1)|| (ind>0 && grid[j][ind]==-1 && grid[j][ind-1]==1)){
                    ind = -1;
                    break;
                }
                
                if((ind==0 && grid[j][ind]==-1) || (ind==n-1 && grid[j][ind]==1)){
                    ind=-1;
                    break;
                }
                if(grid[j][ind]==1)
                    ind++;
                if(grid[j][ind]==-1)
                    ind--;
                
            }
            ans[i]=ind;
        }
        return ans;
    }
};