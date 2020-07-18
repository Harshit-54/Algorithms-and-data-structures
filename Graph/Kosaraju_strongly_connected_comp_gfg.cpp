// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

 // } Driver Code Ends


/*  Function to find the number of strongly connected components
*   using Kosaraju's algorithm
*   V: number of vertices
*   adj[]: array of vectors to represent graph
*/

void dfs(stack<int> &st, vector<int> adj[],int node, vector<int> &vis){
    if(vis[node]==1)return;
    else {
        vis[node]=1;
        // cout<<"N=>"<<node<<" ";
        for(int i=0;i<adj[node].size();i++){
            if(vis[adj[node][i]]==0){
                // cout<<"he";
                dfs(st,adj,adj[node][i],vis);
            }
        }
        st.push(node);
    }
}

int kosaraju(int V, vector<int> adj[])
{
    // Your code here
    stack<int> st;
    vector<int> vis(V,0);
    for(int i=0;i<V;i++){
        if(vis[i]==0){
            dfs(st,adj,i,vis);
        }
    }
    vector<int> adj2[V];
    for(int i=0;i<V;i++){
        for(int j=0;j<adj[i].size();j++){
            adj2[adj[i][j]].push_back(i);
        }
    }
    
    for(int i=0;i<V;i++)vis[i]=0;
    // cout<<st.size()<<" d";
    int count=0;
    stack<int> temp;
    while(!st.empty()){
        int node=st.top();
        // cout<<"node"<<node<<"|";
        st.pop();
        if(vis[node]==0){
            dfs(temp,adj2,node,vis);
            count++;        
        }
    }
    return count;
    

}

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        int m, n;
        vector<int> adj[a];
        for (int i = 0; i < b; i++) {
            cin >> m >> n;
            adj[m].push_back(n);
        }
        cout << kosaraju(a, adj) << endl;
    }
    return 0;
}
  // } Driver Code Ends