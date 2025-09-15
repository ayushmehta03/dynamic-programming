#include<iostream>
using namespace std;


int f(int i,int j,string &s,string &t){
    if(i<0) return j+1;
    if(j<0) return i+1;

    if(s[i]==t[j]){
        return f(i-1,j-1,s,t);
    }

    return min((1+f(i,j-1,s,t),1+f(i-1,j,s,t)),1+f(i-1,j-1,s,t));

}




int main(){
    string s="horse";
    string t="ros";
    int n=s.size();
    int m=t.size();
    int ans=f(n-1,m-1,s,t);

    cout<<"The min ops req to convert the string is:"<<" "<<ans;
    return 0;

}
