#include<iostream>
#include<algorithm>
using namespace std;

//Minimum Insertions/Deletions to Convert String |

int f(int i,int j,string &s,string &t){
    if(i<0||j<0) return 0;

    if(s[i]==t[j]) return 1+f(i-1,j-1,s,t);


    return max(f(i-1,j,s,t),f(i,j-1,s,t));


}




int main(){
    string s="leetcode";
    string t="etco";

    int n=s.size();
    int m=t.size();

    int lcs=f(n-1,m-1,s,t);

    // total no of operations including deletion and insertion
    int ans=(m+n)-2*lcs;
    cout<<"No of opertaions needed to convert string 1 to string 2 is:"<<" "<<ans;
    return 0;
}