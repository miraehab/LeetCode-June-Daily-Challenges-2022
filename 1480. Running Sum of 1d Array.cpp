class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        long long cumSum = 0;
        vector<int> ans(nums.size());
        for(int i = 0; i < nums.size(); ++i){
            cumSum+=nums[i];
            ans[i] = cumSum;
        }
        return ans;
    }
};