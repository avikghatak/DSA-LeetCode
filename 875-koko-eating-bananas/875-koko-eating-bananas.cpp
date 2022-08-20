class Solution {
public:
    bool canFinish(vector<int>& piles,int speed,int maxHours) {
        long long time=0;
        for(int i=0;i<piles.size();i++){
            
            time +=ceil((double)piles[i]/speed);
            if(time>maxHours)return false;
        }
        return true;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1,high=*max_element(piles.begin(),piles.end()),ans=-1;
        while(low<=high) {
            int mid = low+(high-low)/2;
            if( canFinish(piles,mid,h)) {
                ans=mid;
                high=mid-1;
            }
            else
                low=mid+1;
        }
        return ans;
    }
};