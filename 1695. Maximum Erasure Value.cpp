class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int maxi = 0, cum_sum = 0, left = 0;
        unordered_set<int> seen;
        for (int j = 0; j < nums.size(); j++) {
            while (seen.find(nums[j]) != seen.end()) {
                seen.erase(nums[left]);
                cum_sum -= nums[left];
                ++left;
            }
            seen.insert(nums[j]);
            cum_sum += nums[j];
            maxi = max(maxi, cum_sum);
        }
        return maxi;
    }
};