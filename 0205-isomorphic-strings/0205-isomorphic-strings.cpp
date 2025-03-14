class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.size(), m = t.size();
        if(n != m) return false;

        map<char, int>m1, m2;

        for(int i=0; i<n; i++)
        {
            if(m1.find(s[i]) == m1.end() && m2.find(t[i]) == m2.end())
            {
                m1[s[i]] = t[i];
                m2[t[i]] = s[i];
            }
            else if(m1[s[i]] != t[i]) return false;
        }

        return true;
    }
};