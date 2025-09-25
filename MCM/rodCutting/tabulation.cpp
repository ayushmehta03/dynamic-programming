#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

int minCost(int n,int c,vector<int>&cuts){
    cuts.push_back(n);
    cuts.insert(cuts.begin(),0);
    sort(cuts.begin(),cuts.end());


    vector<vector<int>>dp(c+2,vector<int>(c+2,0));

    for(int i=c;i>=1;i--){
        for(int j=1;j<=c;j++){
            int mini=INT_MAX;
            if(i>j) continue;
            for(int idx=i;idx<=j;idx++){
                int cost=cuts[j+1]-cuts[i-1]+dp[i][idx-1]+dp[idx+1][j];
                mini=min(mini,cost);

            }
            dp[i][j]=mini;
        }
    }
    return dp[1][c];


}

int main(){
        int n=7;
    vector<int>cuts={1,3,4,5};
    int c=cuts.size();
    int ans=minCost(n,c,cuts);
    cout<<"The minimu cost incurred is: "<<ans;
    return 0;
}
