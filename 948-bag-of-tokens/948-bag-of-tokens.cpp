class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int score = 0, ans =0;
        int i=0, j= tokens.size()-1;
        sort(tokens.begin(), tokens.end());
        while(i<=j){
            if(power >= tokens[i]){
                score++;
                power -= tokens[i];
                i++;
            }else if(score > 0){
                score--;
                power += tokens[j];
                j--;
            }else{
                break;
            }
            ans = max(score, ans);
        }
        return ans;
    }
};