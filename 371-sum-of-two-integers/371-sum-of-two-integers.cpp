class Solution {
public:
    //addition of two integers  is basically XOR 
    //but in case of carry, we want to add that 1 on the right pos of current digit
    int getSum(int a, int b) {
        //we store carry in  b ans result in a
        while(b!=0){
            //& will give 1 only when both digits are 1 ie case of carry
            unsigned int carry = (a&b);
            a = (a^b);
            //we keep adding the carry until no carry is left
            b = carry<<1;
        }
        return a;
    }
};