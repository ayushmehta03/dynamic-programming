#include<iostream>
#include<vector>
using namespace std;


int knapSack(vector<int>&wt,vector<int>&val,int cap){
   int n=val.size();
   
    vector<vector<int>>dp(n,vector<int>(cap+1,0));
    for(int t=0;t<=cap;t++){
        if(wt[0]<=t){
            dp[0][t]=(wt[0]/t)*val[0];
        }
    }

    for(int idx=1;idx<n;idx++){
        for(int c=0;c<=cap;c++){
            int nPick=dp[idx-1][c];
            int pick=0;
            if(wt[idx]<=c){
                pick=val[idx]+dp[idx][c-wt[idx]];
            }

            dp[idx][c]=max(nPick,pick);

        }
    }

            return dp[n-1][cap];

}

int main(){
    vector<int>wt={2,4,6};
    vector<int>val={5,11,13};
    int capacity=10;

    int n=wt.size();

    int ans=knapSack(wt,val,capacity);
    cout<<"The max we can get is:"<<" "<<ans;

    return 0;



}

