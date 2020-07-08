#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;cin>>t;
	while(t--){
	    int l;cin>>l;
	    vector<int> cuts(3,0);
	    cin>>cuts[0]>>cuts[1]>>cuts[2];
	    vector<int> dp(l+1,-1);
	    dp[0]=0;
	    for(int i=1;i<l+1;i++){
	        int maxlen=-1;
	        for(int j=0;j<3;j++){
	            if(cuts[j]<=i && dp[i-cuts[j]]!=-1){
	                if(maxlen<dp[i-cuts[j]]+1)maxlen=dp[i-cuts[j]]+1;
	            }
	        }
	        dp[i]=maxlen;
	    }
	    cout<<dp[l]<<endl;
	    
	}
	return 0;
}