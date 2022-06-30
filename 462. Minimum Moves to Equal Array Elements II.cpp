class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int num = 0;
        
        sort(nums.begin(), nums.end());
        //to reduce the complexity to O(n) instead of O(nlog(n))
        //nth_element(nums.begin(), nums.begin()+(nums.size()/2), nums.end());
        
        //get the median of the sorted array
        if(nums.size()%2 == 0) num = (nums[nums.size()/2]+nums[(nums.size()/2)-1])/2;
        else num= nums[nums.size()/2];
        //num = nums[nums.size()/2];
        
        int ans = 0;
        for(int i = 0; i < nums.size(); ++i) ans += abs(num-nums[i]);
        
        return ans;
    }
};