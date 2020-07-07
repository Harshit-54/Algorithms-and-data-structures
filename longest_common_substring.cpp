#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;cin>>t;
	while(t--){
	    int n,m;cin>>n>>m;
	    string nstr,mstr;cin>>nstr>>mstr;
	    vector<vector<int>> mat(n,vector<int> (m,0));
	    int maxval=0;
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            if(i==0 || j==0){
	                if(nstr[i]==mstr[j]){
	                    mat[i][j]=1;
	                    maxval=max(maxval,mat[i][j]);
	                }else mat[i][j]=0;
	            }else {
	                if(nstr[i]==mstr[j]){
	                    mat[i][j]=mat[i-1][j-1]+1;
	                    maxval=max(maxval,mat[i][j]);
	                }else mat[i][j]=0;
	            }
	        }
	    }
	    cout<<maxval<<endl;
	}
	return 0;
}