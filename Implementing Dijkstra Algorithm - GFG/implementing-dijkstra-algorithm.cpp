//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,S});
        int dist[V];
        for(int i=0;i<V;i++) dist[i]=1e9;
            dist[S]=0;
        vector<int>ans(V,-1);
        while(pq.empty()==false){
            int node=pq.top().second;
            int distance=pq.top().first;
            pq.pop();
            //neighbours
            for(auto it:adj[node]){
                int n=it[0];
                int wt=it[1];
                
                if(dist[n]>dist[node]+wt){
                    dist[n]=dist[node]+wt;
                    pq.push({dist[n],n});
                }
            }
        }
        for(int i=0;i<V;i++) 
        if(dist[i]!=1e9) ans[i]=dist[i];
        return ans;
}
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends