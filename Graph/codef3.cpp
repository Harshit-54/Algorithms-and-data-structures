#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;


ll getpcomepc(int node,vector<ll> &pcomepc,vector<vector<int>> &tree, vector<int> &ppc,vector<int> &hpc,bool &ans){
	if(tree[node].size()==0){
	    
		pcomepc[node]=ppc[node];
		if(abs(hpc[node])>pcomepc[node]){
		    ans=false;
		}
		return ppc[node];
	}
	ll ret=0;
	for(int i=0;i<tree[node].size();i++){
		ret+=getpcomepc(tree[node][i],pcomepc,tree,ppc,hpc,ans);
	}
	pcomepc[node]=ret+ppc[node];
	if(abs(hpc[node])>pcomepc[node]){
		    ans=false;
	}
	return pcomepc[node];

}

pair<ll,ll> solve(int node,vector<ll> &pcomepc,vector<vector<int>> &tree, vector<int> &ppc, vector<int> &hpc, bool &ans){
	if(tree[node].size()==0){
		ll hp=(pcomepc[node]+hpc[node])/2;
		if((pcomepc[node]+hpc[node])%2==1){
	    ans=false;
	    }
		ll sp=(pcomepc[node]-hpc[node])/2;
		if((pcomepc[node]-hpc[node])%2==1){
	    ans=false;
	    }
// 		cout<<node<<"("<<hp<<","<<sp<<") ";
		return make_pair(hp,sp);
	}
	pair<ll,ll> ret;
	ret=make_pair(0,0);
	for(int i=0;i<tree[node].size();i++){
		pair<ll,ll> call=solve(tree[node][i],pcomepc,tree,ppc,hpc,ans);
		ret.first+=call.first;
		ret.second+=call.second;
	}

	ll hp=(pcomepc[node]+hpc[node])/2;
	if((pcomepc[node]+hpc[node])%2==1){
	    ans=false;
	}
	ll sp=(pcomepc[node]-hpc[node])/2;
	if((pcomepc[node]-hpc[node])%2==1){
	    ans=false;
	}
// 	cout<<node<<"("<<hp<<","<<sp<<") ";
	if(ppc[node]<=sp){
		if(hp<ret.first){
			ans =false;
// 			cout<<"+++";
		}
	}else {
		hp= hp+sp-ppc[node];
		if(hp<ret.first){ans =false;}
	}
	
	return make_pair(hp,sp);

}



int main(){


	int t;cin>>t;
	while(t--){
		int n,m;cin>>n>>m;
		vector<int> ppc(n+1,0);
		for(int i=1;i<n+1;i++){
			cin>>ppc[i];
		}
		vector<int> hpc(n+1,0);
		for(int i=1;i<n+1;i++){
			cin>>hpc[i];
		}
		
		vector<ll> pcomepc(n+1,0);
		vector<vector<int>> tree(n+1);
		for(int i=0;i<n-1;i++){
			int x,y;cin>>x>>y;
			tree[min(x,y)].push_back(max(x,y));
		} 
// 		for(int i=1;i<n+1;i++){
// 			for(int j=0;j<tree[i].size();j++){
// 			    cout<<tree[i][j]<<" ";    
// 			}
// 			cout<<endl;
// 		} 
		bool ans=true;
		getpcomepc(1,pcomepc,tree,ppc,hpc,ans);
		for(int i=1;i<n+1;i++){
// 		cout<<pcomepc[i]<<" ";
		} 
		
		solve(1,pcomepc,tree,ppc,hpc,ans);
		if(ans==false){
			cout<<"NO"<<endl;
		}else cout<<"YES"<<endl;
	}
	return 0;

}