#include<bits/stdc++.h>

using namespace std;

int main(){


	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		long long int ans=0;
		int x=n/4+1;
		for(int i=0;i<n-x;i++){
			ans=ans*10+9;
		}
		for(int i=0;i<x;i++){
			ans=ans*10+8;
		}
		cout<<ans<<endl;
	}
	return 0;

}