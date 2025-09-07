#include <iostream>
#include <vector>
using namespace std;

int f(vector<int>& nums, int target, int idx, vector<vector<int>>& dp) {
    if (idx == 0) {
        if (target == 0 && nums[0] == 0) return 2;   // two ways: pick or not pick
        if (target == 0 || nums[0] == target) return 1;
        return 0;
    }

    if (dp[idx][target] != -1) return dp[idx][target];

    int notTake = f(nums, target, idx - 1, dp);
    int take = 0;
    if (nums[idx] <= target) {
        take = f(nums, target - nums[idx], idx - 1, dp);
    }

    return dp[idx][target] = take + notTake;
}

int findWays(vector<int>& nums, int tar) {
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(tar + 1, -1));
    return f(nums, tar, n - 1, dp);
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
