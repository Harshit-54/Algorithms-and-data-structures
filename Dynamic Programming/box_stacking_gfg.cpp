// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

int maxHeight(int height[],int width[],int length[],int n);

int main()
{
	int t;
	cin>>t;
	while(t--){
	int n;
	cin>>n;
	

 	int A[1000],B[1000],C[10001];
	for(int i=0;i<n;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		A[i]=a;
		B[i]=b;
		C[i]=c;
	}
	cout<<maxHeight(A,B,C,n)<<endl;
}
 
} // } Driver Code Ends


/*The function takes an array of heights, width and 
length as its 3 arguments where each index i value 
determines the height, width, length of the ith box. 
Here n is the total no of boxes.*/
struct box{
    int one;
    int two;
    int three;
};
bool compare(struct box a, struct box b){
    if(a.one>b.one)return true;
    else if(a.one==b.one){
        if(a.two>b.two)return true;
        else return false;
    }else return false;
}
int maxHeight(int height[],int width[],int length[],int n)
{
    //Your code here
    // cout<<n<<" ";
    vector<struct box> v;
    for(int i=0;i<n;i++){//cout<<height[i]<<" "<<width[i]<<" "<<length[i]<<endl;}
        struct box b1;
        int first,second,third;
        vector<int> w(3,0);w[0]=width[i];w[1]=height[i];w[2]=length[i];
        sort(w.begin(),w.end());
        first=w[0];second=w[1];third=w[2];
        // b1= {third,second,first};
        b1.one=third;
        b1.two=second;
        b1.three=first;
        // cout<<"heryey"<<b1.one<<"||";
        v.push_back(b1);
        b1.one=third;
        b1.two=first;
        b1.three=second;
        v.push_back(b1);
        // cout<<"heryey"<<b1.one<<"||";
        b1.one=second;
        b1.two=first;
        b1.three=third;
        v.push_back(b1);
        //  cout<<"heryey"<<b1.one<<"||";
    }
    sort(v.begin(),v.end(),compare);
    // cout<<endl;
    // for(int i=0;i<3*n;i++){
    //     cout<<v[i].one<<v[i].two<<v[i].three<<endl;
    // }
    vector<int> dp(3*n,0);
    int maxval=0;
    for(int i=0;i<3*n;i++){
        int maxh=0;
        for(int j=0;j<i;j++){
            if(v[j].one>v[i].one && v[j].two>v[i].two){
                maxh=max(maxh,dp[j]);
            }
        }
        dp[i]=maxh+v[i].three;
        maxval=max(dp[i],maxval);
    }
    // cout<<"Ans is "<<maxval<<endl;
    return maxval;
    
    
    
}