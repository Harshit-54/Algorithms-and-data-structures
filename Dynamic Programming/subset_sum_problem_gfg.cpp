#include <bits/stdc++.h>
using namespace std;

int getans(vector<vector<int>> &dp, vector<int> &v, int i, int j){
    if(i==0)return 1;
    else if(j==0)return 0;
    else {
        if(dp[i][j]!=-1)return dp[i][j];
        if(v[j-1]<=i){
            dp[i][j]=max(getans(dp,v,i-v[j-1],j-1),getans(dp,v,i,j-1));
        }else {
            dp[i][j]=getans(dp,v,i,j-1);
        }
        return dp[i][j];
    }
}

int main() {
	//code
	int t;cin>>t;
	while(t--){
	    long n;cin>>n;vector<int> v(n,0);
	    long sum=0;
	    for(int i=0;i<n;i++){cin>>v[i];sum+=v[i];}
	    if(sum%2!=0){
	        cout<<"NO"<<endl;continue;
	    }
	    long N=sum/2;
	    vector<vector<int>> dp(N+1,vector<int> (n+1,-1));
	    for(int i=0;i<n+1;i++)dp[0][i]=1;
	    for(int i=1;i<N+1;i++)dp[i][0]=0;
	    bool x=getans(dp, v, N,n);
	   
	   // for(int i=1;i<N+1;i++){
	   //     for(int j=1;j<n+1;j++){
	   //         if(v[j-1]<=i && dp[i-v[j-1]][j]!=false){
	   //             dp[i][j]=dp[i-v[j-1]][j-1] || dp[i][j-1];
	   //         }else {
	   //             dp[i][j]=dp[i][j-1];   
	   //         }
	   //     }
	   // }
	    if(dp[N][n]==1)
	    cout<<"YES"<<endl;
	    else cout<<"NO"<<endl;
	    
	}
	return 0;
}