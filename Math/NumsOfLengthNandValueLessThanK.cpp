int getnum(int x, vector<int> &A){
    int i=0;
    while(i<A.size() && A[i]<x){
        i++;
    }
    return i;
}

int ispresent(int x, vector<int> &A){
    int i=0;
    while(i<A.size()){
        if(A[i]==x)return 1;
        i++;
    }
    return 0;
}
int getlen(int x){
    int count=0;
    while(x>0){
        count++;x/=10;
    }
    return count;
}

int countnums(int n, vector<int> &A, int tenspos, int C, int ifzero){
    if(n==0)return 0;
    int thisdigit=n/tenspos;
    int ans=0;
    if(n==C && ifzero){
        ans =(getnum(thisdigit,A)-1)*pow(A.size(),getlen(n)-1);
    }else {
        ans= getnum(thisdigit,A)*pow(A.size(),getlen(n)-1);
    }
    if(ispresent(thisdigit, A)){
        return ans+countnums(n%tenspos, A,tenspos/10,C,ifzero);
    }else {
        return ans;
    }
}

int Solution::solve(vector<int> &A, int B, int C) {
    int len = getlen(C);
    int ifzero=0;
    if(A.size()==0)return 0;
    if(A[0]==0)ifzero=1;
    if(B==1 && C>=1 && C>0 && A[0]==0){
        return getnum(C,A);
    }
    if(B>len){
        return 0;
    }else if(B<len){
        long long int ans=1;
        for(int i=0;i<B;i++){
            if(ifzero && i==0){
                ans*=(A.size()-1);
            }else {
                ans*=A.size();
            }
        }   
        return ans;
    }else {
        int n=C;
        int tenspos=pow(10,len-1);
        return countnums(n,A,tenspos,C,ifzero);
    }
    return 0;
    
}
