class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int i = 0, j = 0;

        while(i < str1.size() && j < str2.size())
        {
            if(str1[i] == str2[j])
            {
                j++;
            }
            else if((str1[i] + 1 - 'a') % 26 == str2[j] - 'a')
            {
                j++;
            }
            i++;
        }

        return j == str2.size();
    }
};