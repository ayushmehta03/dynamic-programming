 #include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> nums = {2,3,1,1};
    int T = 4;
    int n = nums.size();

    vector<vector<bool>> dp(n, vector<bool>(T+1, false));

    for(int i=0;i<n;i++) dp[i][0] = true;

      dp[0][nums[0]] = true;

    for(int i=1; i<n; i++){
        for(int t=1; t<=T; t++){
            bool notTake = dp[i-1][t];
            bool take = false;
            if(t >= nums[i]){
                take = dp[i-1][t - nums[i]];
            }
            dp[i][t] = take || notTake;
        }
    }

    if(dp[n-1][T]) cout << "Yes";
    else cout << "No";

    return 0;
}