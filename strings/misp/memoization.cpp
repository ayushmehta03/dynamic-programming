//Minimum insertions to make string palindrome
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int f(int i,int j,string &s,string &t,    vector<vector<int>>&dp){
    if(i<0||j<0){
        return 0;
    }
    if(dp[i][j]!=-1) return dp[i][j];
    if(s[i]==t[j]){
      return  1+f(i-1,j-1,s,t,dp);
    }


    return dp[i][j]= max(f(i-1,j,s,t,dp),f(i,j-1,s,t,dp));


}

int main(){
    string s="leetcode";
    string t=s;
    reverse(t.begin(),t.end());
    int n=s.size();
    int m=t.size();
    vector<vector<int>>dp(n,vector<int>(m,-1));

    int lps=f(n-1,m-1,s,t,dp);
    int ans=n-lps;
    if(ans>0){
        cout<<"The min insertion steps to make string palindrome:"<<" "<<ans;

    }
    else{
        cout<<"The given string is already palindrome";
    }


}