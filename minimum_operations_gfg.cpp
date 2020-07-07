#include <bits/stdc++.h>
using namespace std;

int getsteps(int n){
    if(n==0)return 0;
    if(n%2==0){
        return getsteps(n/2)+1;
    }else {
        return getsteps(n-1)+1;
    }
}

int main() {
	//code
	int t;cin>>t;
	while(t--){
	   int n;cin>>n;
	   cout<<getsteps(n)<<endl;
	}
	return 0;
}