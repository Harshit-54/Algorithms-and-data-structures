#include <bits/stdc++.h>
using namespace std;



int getval(vector<vector<int>> &dp,vector<int> &val,vector<int> &wt,int n,int W){
    if(W==0 || n==0){
        return 0;
    }else if(dp[W][n]!=-1){
        return dp[W][n];
    }else {
        if(wt[n-1]<=W){
            dp[W][n]= max(getval(dp,val,wt,n-1,W-wt[n-1])+val[n-1],getval(dp,val,wt,n-1,W));
            return dp[W][n];
        }else {
            dp[W][n]= getval(dp,val,wt,n-1,W);
            return dp[W][n];
        }
    }
}


int main() {
	//code
	int t;cin>>t;
	while(t--){
	    int n,W;cin>>n>>W;vector<int>val(n,0),wt(n,0);
	    for(int i=0;i<n;i++){
	       cin>>val[i];
	    }
	    for(int i=0;i<n;i++){
	       cin>>wt[i];
	    }
	    vector<vector<int>> dp(W+1,vector<int>(n+1,-1));
	    for(int i=0;i<n+1;i++)dp[0][i]=0;
	    for(int i=0;i<W+1;i++)dp[i][0]=0;
	   // for(int i=1;i<W+1;i++){
	   //     for(int j=1;j<n+1;j++){
	   //         if(wt[j-1]<=i){
	   //             dp[i][j]=max(val[j-1]+dp[i-wt[j-1]][j-1],dp[i][j-1]);
	   //         }else {
	   //             dp[i][j]=dp[i][j-1];
	   //         }
	   //     }
	   // }
	   // cout<<dp[W][n]<<endl;
	    cout<<getval(dp,val,wt,n,W)<<endl;
	    
	}
	return 0;
}