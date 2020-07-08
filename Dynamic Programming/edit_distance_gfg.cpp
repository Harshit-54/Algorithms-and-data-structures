#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;cin>>t;
	while(t--){
	    int n,m;cin>>n>>m;
	    string nstr,mstr;cin>>nstr>>mstr;
	    vector<vector<int>> v(n+1,vector<int>(m+1,0));
	    
	    for(int i=0;i<n+1;i++)v[i][0]=i;
	    for(int i=0;i<m+1;i++)v[0][i]=i;
	    
	    for(int i=1;i<n+1;i++){
	        for(int j=1;j<m+1;j++){
	            if(mstr[j-1]==nstr[i-1]){
	                v[i][j]=v[i-1][j-1];
	            }else {
	                v[i][j]=min(v[i-1][j],min(v[i][j-1],v[i-1][j-1]))+1;
	            }
	        }
	    }
	    cout<<v[n][m]<<endl;
	}
	return 0;
}