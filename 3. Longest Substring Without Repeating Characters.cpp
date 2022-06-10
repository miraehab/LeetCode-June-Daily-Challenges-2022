class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> vis_indexes(256, -1);
        int maxi = 0, start = -1;
        for (int i = 0; i != s.length(); i++) {
            if (vis_indexes[s[i]] > start) start = vis_indexes[s[i]];
            vis_indexes[s[i]] = i;
            maxi = max(maxi, i - start);
        }
        return maxi;
    }
};