#include<iostream>
#include<vector>
using namespace std;


// tc is O(n)
// sc is O(n)
int fibwithArr(int n, vector<int>&dp){
     if (n==0 ) return 0;
    if(n==1 ) return 1;
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}

// tc-0(n) -> linear
// sc-O(1) 
int fibWvar(int n){
    if (n==0 ) return 0;
    if(n==1 ) return 1;
    int prev2=0,prev1=1,curr;
    for(int i=2;i<=n;i++){
        curr=prev1+prev2;
        prev2=prev1;
        prev1=curr;
    }
    return prev1;
}

int main(){
    int n;
    cin>>n;
    int ans=fibWvar(n);

    vector<int>dp(n+1);
    int ans2=fibwithArr(n,dp);
    cout<<"The fibonaci value at the "<<" "<<n<<" place is "<<" "<<ans2;
    return 0;
}