#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;cin>>t;
	while(t--){
	    int n;cin>>n;
	    vector<int> v(n,0);
	    for(int i=0;i<n;i++)cin>>v[i];
	    vector<int> dp=v;
	    int maxval=v[0];
	    dp[0]=v[0];
	    for(int i=1;i<n;i++){
	        for(int j=0;j<i;j++){
	            if(v[i]>v[j]){
	                dp[i]=max(dp[j]+v[i],dp[i]);
	                maxval=max(dp[i],maxval);
	            }
	        }
	    }
	    cout<<maxval<<endl;
	    
	    
	}
	return 0;
}
