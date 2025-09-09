#include<iostream>
#include<vector>
using namespace std;



int f(int idx,vector<int>&wt,vector<int>&val,int cap){
    if(idx==0){
        if(wt[0]<=cap){
            return (wt[0]/cap)*val[0];
        }
        return 0;
    }

    int nPick=f(idx-1,wt,val,cap);
    int pick=0;
    if(wt[idx]<=cap){
        pick=val[idx]+f(idx,wt,val,cap-wt[idx]);
    }

    return max(pick,nPick);


}

int main(){
    vector<int>wt={2,4,6};
    vector<int>val={5,11,13};
    int capacity=10;

    int n=wt.size();

    int ans=f(n-1,wt,val,capacity);
    cout<<"The max we can get is:"<<" "<<ans;

    return 0;



}