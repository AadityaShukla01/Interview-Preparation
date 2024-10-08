//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int sol(int m ,int n ,string& s1,string& s2,vector<vector<int>>&dp){
        for(int i=0;i<s1.size()+1;i++){
            for(int j=0;j<s2.size()+1;j++){
                if(i==0)
                dp[i][j]=0;
                if(j==0)
                dp[i][j]=0;
            }
        }
        for(int i=1;i<s1.size()+1;i++){
            for(int j=1;j<s2.size()+1;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }
    int lcs(int x, int y, string s1, string s2)
    {
        // your code here
        int m=s1.size();
        int n=s2.size();
         vector<vector<int>>dp(m+1,vector<int>(n+1,0));
         for(int i=0;i<s1.size()+1;i++){
            for(int j=0;j<s2.size()+1;j++){
                if(i==0)
                dp[i][j]=0;
                if(j==0)
                dp[i][j]=0;
            }
        }
        int q=0;
        for(int i=1;i<s1.size()+1;i++){
            for(int j=1;j<s2.size()+1;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                    q=max(q,dp[i][j]);
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        
       return dp[m][n];
    }
};


//{ Driver Code Starts.
int main()
{
    int t,n,k,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends