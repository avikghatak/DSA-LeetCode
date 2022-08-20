class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int lastBit=0,ans=0;
        for(int i=32;i>0;i--){
            //store last bit of n in lastBit
            lastBit = n&1;
            //set the last bit of ans to lastBit
            ans = ans|lastBit;
            //right shift n to get the next lastBit
            n = n>>1;
            //left shift ans to set the last bit except when i = 1(last iteration)
            if(i>1)
                ans = ans<<1;
        }
        return ans;
    }
};