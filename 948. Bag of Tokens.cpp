class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int ans = 0, score = 0;
        vector<int> t = tokens;
        sort(t.begin(), t.end());
        int start = 0, end = t.size()-1;
        while(start <= end){
            if(power >= t[start]){
                power-= t[start];
                ++score;
                ++start;
                ans = max(score, ans);
            }else if(score > 0){
                power += t[end];
                --end;
                --score;
                ans = max(score, ans);
            }else{
                break;
            }
        }
        return ans;
    }
};