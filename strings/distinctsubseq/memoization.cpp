#include<iostream>
#include<vector>
using namespace std;

int f(int i,int j,string &s,string &t,vector<vector<int>>&dp){
    if(j<0) return 1;
    if(i<0) return 0;

    if(dp[i][j]!=-1) return dp[i][j];
    if(s[i]==t[j]){
        return f(i-1,j-1,s,t,dp)+f(i-1,j,s,t,dp);
    }

    return dp[i][j]= f(i-1,j,s,t,dp);

}

int main(){
    string s="babgbag";
    string t="bag";
    int n=s.size();
    int m=t.size();
    vector<vector<int>>dp(n,vector<int>(m,-1));

    int ans=f(n-1,m-1,s,t,dp);
    cout<<ans;

}