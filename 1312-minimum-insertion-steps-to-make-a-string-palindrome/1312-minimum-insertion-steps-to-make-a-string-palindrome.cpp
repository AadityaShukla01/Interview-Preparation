class Solution {
public:
int sol(string x , string y,int n,int m,vector<vector<int>>&dp){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || j==0){
                    dp[i][j]=0;
                }
            }
        }
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(x[i-1]==y[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
    int longestPalindromeSubseq(string &s) {
        int i=s.size();
        int size=s.size();
        string t=s;
        reverse(s.begin(),s.end());
        vector<vector<int>>dp(s.size()+1,vector<int>(s.size()+1,-1));
        return sol(s,t,i,i,dp);
    }
    int minInsertions(string s) {
        return s.size()-longestPalindromeSubseq(s);
    }
};