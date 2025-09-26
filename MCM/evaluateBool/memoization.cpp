#include<iostream>
#include<vector>
using namespace std;

int f(int i,int j,int isTrue,string &s,vector<vector<vector<int>>>&dp){
    if(i>j) return 0;
    if(i==j){
        if(isTrue==1) return s[i]=='T'?1:0;
        else return s[i]=='F'?1:0;
    }
    if(dp[i][j][isTrue]!=-1) return dp[i][j][isTrue];

    int ways=0;

    for(int idx=i+1;idx<=j-1;idx+=2){
        int lT=f(i,idx-1,1,s,dp);
        int lF=f(i,idx-1,0,s,dp);
        int rT=f(idx+1,j,1,s,dp);
        int rF=f(idx+1,j,0,s,dp);


        if(s[idx]=='&'){
            if(isTrue) ways=(ways+lT*rT);
            else ways=(ways+(lF*rT)+(lT*rF)+(lF*rF));
        }
        else if(s[idx]=='|'){
            if(isTrue) ways=(ways+(lF*rT)+(lT*rF)+(lT*rT));
            else ways=ways+(lF*rF);
        }
        else{
            if(isTrue)ways=(ways+(lF*rT)+(lT*rF));
            else ways=(ways+(lF*rF)+(lT*rT));
        }
    }
    return dp[i][j][isTrue]= ways;


}



int evaluateExp(string &exp){
    int n=exp.size();
    vector<vector<vector<int>>>dp(n,vector<vector<int>>(n,vector<int>(2,-1)));
    return f(0,n-1,1,exp,dp);
}

int main(){
    string s ="T|T&F^T";
    int ans=evaluateExp(s);
    cout<<"The total no of ways: "<<ans;
    return 0;
}