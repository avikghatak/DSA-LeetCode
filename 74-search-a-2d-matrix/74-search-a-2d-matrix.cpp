class Solution {
public:
    //binary search on row to find the row containing the element
    //then binary search within the row
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(),n = matrix[0].size();
        if(m == 0||n==0) return false;
        int r1 = 0, r2 = m-1, mid;
        //Binary search on rows
        while(r1 < r2){
            mid = r1 + (r2-r1)/2;
            if(matrix[mid][n-1] < target) r1 = mid+1;
            else if(matrix[mid][0] > target) r2 = mid-1;
            else{
                r1 = mid;
                break;
            }
        }
        //Binary search on cols
        int c1 = 0, c2 = n-1;
        while(c1 <= c2){
            mid = c1 + (c2-c1)/2;
            if(matrix[r1][mid] < target) c1 = mid+1;
            else if(matrix[r1][mid] > target) c2 = mid-1;
            else return true;
        }
        return false;
    }
};