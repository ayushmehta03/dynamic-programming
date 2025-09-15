#include<iostream>
using namespace std;



bool f(int i,int j,string &p,string &s){
    if(i<0&&j<0) return true;

    if(i<0&&j>=0) return false;
    if(j<0 &&i>=0){
        for(int i1=0;i1<=i;i1++){
            if(p[i]!='*') return false;
        }
        return true;
    }


    if(p[i]==s[j]|| p[i]=='?') {
        return f(i-1,j-1,p,s);
    }

    if(p[i]=='*'){
        return f(i-1,j,p,s) ||f(i,j-1,p,s);
    }

 return false;

}

int main(){
    string p="?ay";
    string s="ray";

    int n=p.size();
    int m=s.size();

    bool ans=f(n-1,m-1,p,s);
    if(ans){
        cout<<"Possible";
    }
    else{
        cout<<"Not possible";
    }

    return 0;


}