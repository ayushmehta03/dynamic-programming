#include <iostream>
#include <vector>
using namespace std;


int findWays(vector<int>& nums, int tar) {
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(tar + 1, 0));
    if(nums[0]==0) dp[0][0]=2;
    else dp[0][0]=1;
    if(nums[0]!=0&&nums[0]<=tar) dp[0][nums[0]]=1;

    for(int idx=1;idx<n;idx++){
        for(int t=1;t<=tar;t++){
            int nTake=dp[idx-1][t];

            int take=0;
            if(nums[idx]<=t){
                take=dp[idx-1][t-nums[idx]];
            }
            dp[idx][t]=nTake+take;
          
        }
    }
    return dp[n-1][tar];


}

int main() {
    vector<int> arr = {5, 2, 6, 4};
    int d = 3;
    int ts = 0;

    for (auto &it : arr) ts += it;

    if (ts - d < 0 || (ts - d) % 2) {
        cout << "No pair with difference " << d;
        return 0;
    }

    int ans = findWays(arr, (ts - d) / 2);

    if (ans > 0) {
        cout << "The possible partitions with difference " << d << " is: " << ans;
    } else {
        cout << "No pair with difference " << d;
    }
    return 0;
}

