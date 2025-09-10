#include<iostream>
#include<vector>
#include<climits>
using namespace std;


int f(int N,vector<int>&price){
    int n=price.size();
    vector<vector<int>>dp(n,vector<int>(N+1,0));
   for(int t=0;t<=N;t++){
    dp[0][t]=t*price[0];
   }
   for(int idx=1;idx<n;idx++){
    for(int t=0;t<=N;t++){
        int nTake=dp[idx-1][t];
        int take=INT_MIN;

        int rodLength=idx+1;
        if(rodLength<=t){
        take=price[idx]+dp[idx][t-rodLength];

        }
        dp[idx][t]=max(take,nTake);
    }

   }

   return dp[n-1][N];


}



int main(){
    vector<int>price={1, 5, 8, 9, 10, 17, 17, 20};
    int n=price.size();
    vector<vector<int>>dp(n,vector<int>(n+1,-1));

    int ans=f(n,price);

    cout<<"The maxi obtainble value is:"<<" "<<ans;



}










