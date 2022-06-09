class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int start = 0, end = numbers.size()-1;
        while(numbers[start]+ numbers[end] != target && start < end){
            if(numbers[start]+ numbers[end] > target) --end;
            else if (numbers[start]+ numbers[end] < target) ++start;
            else break;
        }
        vector<int> ans;
        ans.push_back(start+1);
        ans.push_back(end+1);
        return ans;
    }
};