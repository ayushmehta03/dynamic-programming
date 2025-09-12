#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int misp(string &s,string &t){
    int n=s.size();
    int m=t.size();

    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    for(int i=0;i<=n;i++) dp[i][0]=0;
    for(int i=0;i<=m;i++) dp[0][i]=0;


    for(int idx=1;idx<=n;idx++){
        for( int idx2=1;idx2<=m;idx2++){
        if(s[idx-1]==t[idx2-1]){
         dp[idx][idx2]=1+dp[idx-1][idx2-1];
        }

        else{
            dp[idx][idx2]=max(dp[idx][idx2-1],dp[idx-1][idx2]);
        }



        }
    }
    return n-dp[n][m];



}

int main(){
     string s="leetcode";
    string t=s;
    reverse(t.begin(),t.end());

    int ans=misp(s,t);
   
    if(ans>0){
        cout<<"The min insertion steps to make string palindrome:"<<" "<<ans;

    }
    else{
        cout<<"The given string is already palindrome";
    }

}