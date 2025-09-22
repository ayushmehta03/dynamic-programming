#include<iostream>
#include<vector>
using namespace std;

int bioS(vector<int>& nums) {
    int n = nums.size();

    // dp1[i] = LIS ending at i
    vector<int> dp1(n, 1);

    for (int i = 0; i < n; i++) {
        for (int prev = 0; prev < i; prev++) {
            if (nums[i] > nums[prev] && 1 + dp1[prev] > dp1[i]) {
                dp1[i] = 1 + dp1[prev];
            }
        }
    }

    // dp2[i] = LIS starting at i (reverse LIS)
    vector<int> dp2(n, 1);

    for (int i = n - 1; i >= 0; i--) {
        for (int prev = n - 1; prev > i; prev--) {
            if (nums[i] > nums[prev] && 1 + dp2[prev] > dp2[i]) {
                dp2[i] = 1 + dp2[prev];
            }
        }
    }

    // find max bitonic subsequence length
    int maxi = 0;
    for (int i = 0; i < n; i++) {
        maxi = max(maxi, dp1[i] + dp2[i] - 1);
    }

    return maxi;
}

int main() {
    vector<int> nums = {1, 11, 2, 10, 4, 5, 2, 1};
    int ans = bioS(nums);
    cout << ans;  // Expected output: 6
}
