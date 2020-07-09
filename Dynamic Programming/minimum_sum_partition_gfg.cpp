#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;cin>>t;
	while(t--){
	    long n;cin>>n;vector<int> v(n,0);
	    long sum=0;
	    for(int i=0;i<n;i++){cin>>v[i];sum+=v[i];}

	    long N=sum/2;
	    vector<vector<int>> dp(N+1,vector<int> (n+1,-1));
	    int finali=0;
	    for(int i=0;i<n+1;i++)dp[0][i]=1;
	    for(int i=1;i<N+1;i++)dp[i][0]=0;
	    int maxi=0;
	
	    for(int i=1;i<N+1;i++){
	        for(int j=1;j<n+1;j++){
	            if(v[j-1]<=i && dp[i-v[j-1]][j]!=false){
	                dp[i][j]=dp[i-v[j-1]][j-1] || dp[i][j-1];
	            }else {
	                dp[i][j]=dp[i][j-1];   
	            }
	            if(dp[i][j]==1 && maxi<i)maxi=i;
	        }
	        
	    }
	    cout<<sum-2*maxi<<endl;

	    
	}
	return 0;
}