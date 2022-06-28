class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char, int> freq;
        unordered_set<int> check;
        int ans = 0;
        for(int i = 0; i < s.length(); ++i) freq[s[i]]++;
        for(auto i = freq.begin(); i != freq.end(); i++){
            int cur_freq = i->second;
            while(cur_freq > 0 && check.find(cur_freq) != check.end()){
                    --cur_freq;
                    freq[i->first]--;
                    ++ans;
            }
            check.insert(cur_freq);
        }
        return ans;
    }
};