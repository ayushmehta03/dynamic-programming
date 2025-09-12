#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;




int lps(string &s,string &t){
    int n=s.size();
    int m=t.size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    for(int i=0;i<=n;i++) dp[i][0]=0;
    for(int i=0;i<=m;i++) dp[0][i]=0;

    for(int idx=1;idx<=n;idx++){
        for(int idx2=1;idx2<=m;idx2++){
            if(s[idx-1]==t[idx2-1]){
                dp[idx][idx2]=1+dp[idx-1][idx2-1];
            }
            else{
                dp[idx][idx2]=max(dp[idx-1][idx2],dp[idx][idx2-1]);

            }
        }
    }
    return dp[n][m];


}

int main(){
    string s= "bbbab";
    string t=s;
    reverse(t.begin(),t.end());

    int ans=lps(s,t);

    if(ans>0){
        cout<<"longest palindromic  subsequnece is: "<<" "<<ans;

    }

    else{
        cout<<"No palindromic subsequece";
    }




}