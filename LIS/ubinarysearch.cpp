#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int lis(vector<int>& nums) {
    int n = nums.size();
    vector<int> temp; 
    temp.push_back(nums[0]);

    for(int i = 1; i < n; i++) {
        if(nums[i] > temp.back()) {
            temp.push_back(nums[i]);
        } else {
            int idx = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
            temp[idx] = nums[i];
        }
    }

    return temp.size();
}

int main() {
    vector<int> nums = {10,9,2,5,3,7,101,18};

    int ans = lis(nums);

    cout << "The length of LIS is: " << ans << endl;

    return 0;
}
