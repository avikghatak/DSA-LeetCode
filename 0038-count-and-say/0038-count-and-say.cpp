class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        string str = "1";
        for(int i=2;i<=n;i++){
            string temp="";
            int freq=1;
            for(int j=0;j<str.length();j++){
                if(str[j]!=str[j+1]){
                    temp += to_string(freq);
                    temp += str[j];
                    freq=1;
                }
                else 
                    freq++;
            }
            str=temp;
        }
        return str;
    }
};