#include <bits/stdc++.h>
using namespace std;

void getpos(vector<int> &dp,int l,int r, int x, int &pos){
    if(l<=r){
        int m=(l+r)/2;
        if(dp[m]<x){
            getpos(dp,m+1,r,x,pos);
        }else {
            pos=m;
            getpos(dp,l,m-1,x,pos);
        }
    }
}

int main() {
	//code
	int t;cin>>t;
	while(t--){
	    int n;cin>>n;
	    vector<int> v(n,0);
	    for(int i=0;i<n;i++){
	        cin>>v[i];
	    }
	    vector<int> dp(n,0);
	    int l=-1;
	    for(int i=0;i<n;i++){
	        if(l==-1){
	            ++l;
	            dp[l]=v[i];
	        }else if(dp[0]>v[i]){
	            dp[0]=v[i];
	        }else if(dp[l]<v[i]){
	            ++l;
	            dp[l]=v[i];
	        }else {
	            int pos=0;
	            getpos(dp,0,l,v[i],pos);
	            dp[pos]=v[i];
	        }
	    }
	    cout<<l+1<<endl;
	}
	return 0;
}