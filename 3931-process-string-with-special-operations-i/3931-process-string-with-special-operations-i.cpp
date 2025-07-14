class Solution {
public:
    string processStr(string s) {
        string ans = "";

        for(auto c: s){
            if(c == '*'){
                if(ans.size()) ans.pop_back();
            }
            else if(c == '#'){
                ans = ans + ans;
            }
            else if(c == '%'){
                reverse(ans.begin(), ans.end());
            }
            else ans += c;
        }
        return ans;
    }
};