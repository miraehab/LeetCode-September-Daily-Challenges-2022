class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        string tmp = "", ans ="";
        int cnt = 0;
        for(int i = s.length()-1; i >= 0; --i){
            if(s[i] != ' '){
                tmp += s[i];
            }
            if(s[i] == ' ' || i == 0){
                words.push_back(tmp);
                tmp = "";
            }
        }
        
        for(int i = words.size()-1; i >= 0; --i){
            ans += words[i];
            ans += " ";
        }
        
        ans.pop_back();
        return ans;
    }
};