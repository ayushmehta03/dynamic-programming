#include<iostream>
#include<vector>
using namespace std;


bool match(string &p,string &s){
int n=p.size();
int m=s.size();

    vector<vector<bool>>dp(n+1,vector<bool>(m+1,false));

    dp[0][0]=true;
    for(int j=1;j<=m;j++) dp[0][j]=false;

    for(int i=1;i<=n;i++){
        bool flag=true;
        for(int i1=1;i1<=i;i1++){
          if(p[i1-1]!='*'){
            flag=false;
            break;
          }  

        }
        dp[i][0]=flag;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(p[i-1]==s[j-1]|| p[i-1]=='?'){
                dp[i][j]=dp[i-1][j-1];
            }

            else if(p[i-1]=='*'){
                dp[i][j]=dp[i-1][j]||dp[i][j-1];
            }

            else{
                dp[i][j]=false;
            }
        }
    }
    return dp[n][m];




}


int main(){

    string p="?ay";
    string s="ray";
    bool ans=match(p,s);
    if(ans){
        cout<<"Possible";
    }
    else{
        cout<<"Not possible";
    }

}