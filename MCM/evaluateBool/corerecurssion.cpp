#include<iostream>
#include<vector>
using namespace std;

int f(int i,int j,int isTrue,string &s){
    if(i>j) return 0;
    if(i==j){
        if(isTrue==1) return s[i]=='T'?1:0;
        else return s[i]=='F'?1:0;
    }
    int ways=0;

    for(int idx=i+1;idx<=j-1;idx+=2){
        int lT=f(i,idx-1,1,s);
        int lF=f(i,idx-1,0,s);
        int rT=f(idx+1,j,1,s);
        int rF=f(idx+1,j,0,s);


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
    return ways;


}



int evaluateExp(string &exp){
    int n=exp.size();
    return f(0,n-1,1,exp);
}

int main(){
    string s ="T|T&F^T";
    int ans=evaluateExp(s);
    cout<<"The total no of ways: "<<ans;
    return 0;
}