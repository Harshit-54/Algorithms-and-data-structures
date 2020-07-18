#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;cin>>t;
	while(t--){
	    int n,m;
	    cin>>n>>m;
	    int v[n],w[m];
	    for(int i=0;i<n;i++)cin>>v[i];
	    for(int i=0;i<m;i++)cin>>w[i];
	    int i=n-1,j=0;
	    while(i>=0 && j<m && v[i]>w[j]){
	        int temp=v[i];v[i]=w[j];w[j]=temp;
	        i--;j++;
	    }
	    sort(v,v+n);
	    sort(w,w+m);
	   
	    for(int i=0;i<n;i++){cout<<v[i]<<" ";}
	   // cout<<endl;
	    for(int i=0;i<m;i++){cout<<w[i]<<" ";}
	    cout<<endl;
	   // int i=0,j=0,k=0;
	   // long long int maxx=max(v[n-1],w[m-1])+1;
	   // int flag=0;
	   // while(i<n && j<m ){
	   //     if(flag==0){
	   //         if(v[i]%maxx<=w[j]%maxx){
	   //             v[k]= (v[i]%maxx)*maxx+v[k];i++;   
	   //             k++;
	   //             if(k==n){flag=1;k=0;}
	   //         }else {
	   //             v[k]= (w[j]%maxx)*maxx+v[k];j++;   
	   //             k++;
	   //             if(k==n){flag=1;k=0;}
	   //         }
	            
	   //     }else{
	   //         if(v[i]%maxx<=w[j]%maxx){
	   //             w[k]= (v[i]%maxx)*maxx+w[k];i++;   
	   //             k++;
	   //         }else {
	   //             w[k]= (w[j]%maxx)*maxx+w[k];j++;   
	   //             k++;
	   //         }
	   //     }
	   // }
	   // while(i<n){
	   //     if(flag==0){
	   //             v[k]= (v[i]%maxx)*maxx+v[k];i++;   
	   //             k++;
	   //             if(k==n){flag=1;k=0;}
	 	 //   }else{
	   //             w[k]= (v[i]%maxx)*maxx+w[k];i++;   
	   //             k++;
	   //     }
	   // }
	   // while(j<m){
	   //     if(flag==0){
	            
	   //             v[k]= (w[j]%maxx)*maxx+v[k];j++;   
	   //             k++;
	   //             if(k==n){flag=1;k=0;}
	            
	            
	   //     }else{
	            
	   //             w[k]= (w[j]%maxx)*maxx+w[k];j++;   
	   //             k++;
	            
	   //     }
	   // }
	    
	   // for(int i=0;i<n;i++){v[i]=v[i]/maxx;cout<<v[i]<<" ";}
	   //// cout<<endl;
	   // for(int i=0;i<m;i++){w[i]=w[i]/maxx;cout<<w[i]<<" ";}
	   // cout<<endl;
	    
	    
	}
	return 0;
}