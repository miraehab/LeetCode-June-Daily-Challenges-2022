class Solution {
public:
    int minPartitions(string n) {
        int max_digit = INT_MIN;
        for(int i = 0; i < n.length(); ++i) max_digit = max(max_digit, n[i]-'0');
        return max_digit;
    }
};