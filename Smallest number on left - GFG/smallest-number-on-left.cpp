//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> leftSmaller(int n, int a[]){
        // code here
        vector<int>ans;
        stack<int>st;
        for(int i=0;i<n;i++){
            if(st.size()==0)
            ans.push_back(-1);
            
            else if(st.size()>0 && st.top()<a[i])
            ans.push_back(st.top());
            
            else{
                while(st.size()>0 && st.top()>=a[i]){
                    st.pop();
                }
                if(st.size()==0)
                ans.push_back(-1);
                else
                ans.push_back(st.top());
            }
            st.push(a[i]);
            
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i = 0;i < n;i++)
            cin>>a[i];
        
        Solution ob;
        vector<int> ans = ob.leftSmaller(n, a);
        for(int i = 0;i < n;i++)
            cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends