#include <bits/stdc++.h>
using namespace std;

int getans(vector <int> &dp,vector<int> &v,int i){
    if(dp[i]!=-1){
        return dp[i];
    }else {
        int minval=INT_MAX;
        for(int j=0;j<i;j++){
            if(v[j]+j>=i)
           minval=min(minval,getans(dp,v,j)+1);
        }
        // if(dp[i]==INT_MAX)
        dp[i]=minval;return dp[i];
    }
}

int main() {
	//code
	int t;cin>>t;
	while(t--){
	    int n;
	    cin>>n;vector<int> v(n,-1);
	    for(int i=0;i<n;i++){
	        cin>>v[i]; 
	    }
	    vector<int> dp(n,-1);
	    dp[0]=0;
	    int x=getans(dp,v,n-1);
	    if(x>=0)
	    {
	        if(x==INT_MAX)cout<<-1<<endl;
	        else cout<<x<<endl;
	    }
	    
	    else cout<<-1<<endl;
	   // for(int i=0;i<n;i++)cout<<dp[i]<<" ";
	   // cout<<endl;
	}
	return 0;
}