class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int Bytes = 0;
        for( auto x: data)
        {
            //check whether the number is 2/3/4 bytes or 1 byte
            if(Bytes == 0)
            {

                if(( x >> 5) == 0b110) //2 bytes 
                {
                    Bytes = 1;
                }
                else if((x >> 4) == 0b1110) //3 bytes 
                {
                    Bytes = 2;
                }
                else if((x >> 3) == 0b11110) //4 bytes 
                {
                    Bytes = 3;
                }
                else if ((x >> 7)!= 0b0)
                {
                     return false; 
                }
            }
            else
            //check if the next bytes start with 10
            {
                if(( x>>6 )!= 0b10)
                {
                  return false; 
                }
                Bytes--; 
            }
        }
        return Bytes==0 ? true : false;
    }
};