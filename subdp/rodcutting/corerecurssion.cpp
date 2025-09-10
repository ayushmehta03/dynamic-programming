#include<iostream>
#include<vector>
using namespace std;


int f(int idx,int N,vector<int>&price){
    if(idx==0){
        return N*price[0];
    }

    int nTake=0+f(idx-1,N,price);

    int rodLength=idx+1;
    int take=INT_MIN;

    if(rodLength<=N){
        take=price[idx]+f(idx,N-rodLength,price);
    }
    return max(take,nTake);
}



int main(){
    vector<int>price={1, 5, 8, 9, 10, 17, 17, 20};
    int n=price.size();

    int ans=f(n-1,n,price);

    cout<<"The maxi obtainble value is:"<<" "<<ans;



}










