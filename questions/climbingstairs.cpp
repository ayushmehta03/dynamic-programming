#include<iostream>
using namespace std;


int climbeStairs(int n){
    if (n==1) return 1;
    if(n==2) return 2;
    int prev2=1,prev1=2,curr;
    for(int i=3;i<=n;i++){
        curr=prev1+prev2;
        prev2=prev1;
        prev1=curr;
    }
    return prev1;
}


int main(){
    // n= steps to reach the top
    int n=4;

    int distinct=climbeStairs(n);
    cout<<distinct;

}



