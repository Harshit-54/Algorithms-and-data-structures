#include <bits/stdc++.h>
using namespace std;

void getlen(vector<string> &v, vector<int> &vis,vector<vector<int>> &adj, int node,int len,int &maxlen){
    if(vis[node]==1){
        if(node==0)
        maxlen=max(maxlen,len-1);
        return ;
        
    }
    else {
        // maxlen=max(maxlen,len);
        vis[node]=1;
        // cout<<"N=>"<<node<<" " ;
        for(int i=0;i<adj[node].size();i++){
            getlen(v,vis,adj,adj[node][i],len+1,maxlen);
        }
        vis[node]=0;
        
    }
    
}

int main() {
	//code
	int t;cin>>t;
	while(t--){
	    int n;cin>>n;vector<string> v(n,"");
	    for(int i=0;i<n;i++)cin>>v[i];
	    map<char,vector<int>> flet;
	    vector<int> vis(n,0);
	    vector<vector<int>> adj(n);
	    int flag=0;
	    
	    
	    for(int i=0;i<n;i++){
	        if(flet.find(v[i][0])==flet.end()){
	            vector<int> temp;temp.push_back(i);
	            flet[v[i][0]]=temp;
	        }else {
	            flet[v[i][0]].push_back(i);    
	        }
	    } 
	    
	    
	    for(int i=0;i<n;i++){
	        int slen=v[i].length();
	        if(flet.find(v[i][slen-1])!=flet.end()){
	            for(int j=0;j<flet[v[i][slen-1]].size();j++){
	                adj[i].push_back(flet[v[i][slen-1]][j]);
	            }
	        }else {
	            i=n;
	            flag=1;
	        }
	    }
	   // for(int i=0;i<n;i++){
	   //     for(int j=0;j<adj[i].size();j++){
	   //         cout<<adj[i][j]<<" ";
	   //     }
	   //     cout<<endl;
	   // }
	    if(flag==1)cout<<0<<endl;
	    else {
	        int len=1;
	        int maxlen=0;
	       // cout<<"here";
	        getlen(v,vis,adj,0,len,maxlen);
	        if(maxlen==n && n!=1 && n!=0)cout<<1<<endl;
	        else if(n==1 && adj[0].size()==1)cout<<1<<endl; 
	        else cout<<0<<endl;
	    }
	    
	    
	}
	return 0;
}