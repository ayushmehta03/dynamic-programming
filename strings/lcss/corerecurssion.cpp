#include<iostream>
using namespace std;

int f(int i,int j,string &s,string &t){

    // base case 
    if(i<0 ||j<0) return 0;

    if(s[i]==t[j]){
        return 1+f(i-1,j-1,s,t);
    }
    return max(f(i-1,j,s,t),f(i,j-1,s,t));


}


int main(){
  string text1="abcde";
  string text2="ace";

  int n=text1.size();
  int m=text2.size();

  int ans=f(n-1,m-1,text1,text2);
  if(ans) cout<<"The longest common subsequence is:"<<" "<<ans;
    else cout<<"No common subsequence";



}




