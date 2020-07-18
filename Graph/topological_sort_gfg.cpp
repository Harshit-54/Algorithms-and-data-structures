void getit(stack<int> &s, vector<int> &vis, vector<int> adj[], int curr){
    if(vis[curr]==1){
        return ;
    }else {
        vis[curr]=1;
        for(auto a:adj[curr]){
            getit(s,vis,adj,a);
        }
        s.push(curr);
    }
}

vector<int> topoSort(int V, vector<int> adj[]) {
    // Your code here
    stack<int> s;
    vector<int> vis(V,0);
    for(int i=0;i<V;i++){
        getit(s,vis,adj,i);
    }
    vector<int> ans;
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}