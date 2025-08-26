#include<iostream>
#include<vector>
using namespace std;

int f(int ind,vector<int>&heights,vector<int>&dp){
    if(ind==0) return 0;
    if(dp[ind]!=-1) return dp[ind];
    int left=f(ind-1,heights,dp)+abs(heights[ind]-heights[ind-1]);
    int right=INT_MAX;
    if(ind>1) right=f(ind-2,heights,dp)+abs(heights[ind]-heights[ind-2]);
    return dp[ind]=min(left,right);
}

// by tabulation method

int frogJump(int n , vector<int>&heights){
    int prev=0,prev1=0;
    for(int i=1;i<n;i++){
        int fs=prev+abs(heights[i]-heights[i-1]);
        int ss=INT_MAX;
        if(i>1) ss=prev1+abs(heights[i]-heights[i-2]);

        int curri=min(fs,ss);
        prev1=prev;
        prev=curri;
    }
    return prev;

}



int main(){
    vector<int>heights={10,20,30,10};
    int n=heights.size();
    vector<int>dp(n+1,-1);

    int ans=f(n-1,heights,dp);
    cout<<" "<<ans;

    int tab=frogJump(n,heights);
    cout<<" "<<tab;

}