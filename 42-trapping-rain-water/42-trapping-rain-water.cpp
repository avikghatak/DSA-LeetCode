class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        if (n == 0) return 0;
        int lmax[n]; //left max of each element
        int rmax[n]; //right max of each element
        lmax[0]=height[0],rmax[n-1]=height[n-1];
        for (int i=1;i<n;i++) {
            lmax[i]=max(height[i],lmax[i-1]); //pre calculate lmax for each element
        }
        for (int i=n-2;i>0;i--){
            rmax[i]=max(height[i],rmax[i+1]); //pre calculate rmax for each element
        }
        int result=0;
        for(int i=1;i<n-1;i++){
            result += min(lmax[i],rmax[i]) - height[i];
        }
        return result;
    }
};