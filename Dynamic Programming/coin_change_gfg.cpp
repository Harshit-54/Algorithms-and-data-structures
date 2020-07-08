#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;cin>>t;
	while(t--){
	    int n;cin>>n;vector<int> v(n,0);
	    for(int i=0;i<n;i++)cin>>v[i];
	    int N;cin>>N;
	    vector<vector<int>> dp(N+1,vector<int> (n+1,0));
	    for(int i=0;i<n+1;i++)dp[0][i]=1;
	    
	   
	    for(int i=1;i<N+1;i++){
	        for(int j=1;j<n+1;j++){
	            if(v[j-1]<=i && dp[i-v[j-1]][j]!=0){
	                dp[i][j]=dp[i-v[j-1]][j]+dp[i][j-1];
	            }else {
	                dp[i][j]=dp[i][j-1];   
	            }
	        }
	    }
	    cout<<dp[N][n]<<endl;
	    
	}
	return 0;
}