class Solution {
public:
    int dp[40001][3]={};
    int f(vector<int> &a, int n, int currSum)
    {
        if(n==0) return currSum%3?INT_MIN:0;
        
        if(dp[n][currSum]!=0) return dp[n][currSum];

        return dp[n][currSum] = max((a[n-1]+f(a,n-1,(currSum+a[n-1])%3)),(f(a,n-1,currSum)));
    }
    int maxSumDivThree(vector<int>& a) {
        int n=a.size();
        return f(a,n,0);
    }
};