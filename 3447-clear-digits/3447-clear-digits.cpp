class Solution {
public:
    string clearDigits(string s) {
        int n = s.size();
        stack<char>st;

        for(int i=0; i<n; i++)
        {
            if(isdigit(s[i]))
            {
                if(st.size()) st.pop();
            }
            else st.push(s[i]);
        }

        string ans = "";
        while(st.empty() == false)
        {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};