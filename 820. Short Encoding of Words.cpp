class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        unordered_set<string> suffix;
        string ans;
        for(int i = 0; i < words.size(); ++i){
            if(suffix.find(words[i]) == suffix.end()){
                for(int j = 1; j < words[i].length(); ++j){
                    suffix.insert(words[i].substr(j, words[i].length()-j));
                }
            }
        }
        for(int i = 0; i < words.size(); ++i){
            if(suffix.find(words[i]) == suffix.end()){
                ans+=words[i];
                ans+="#";
                suffix.insert(words[i]);
            }
        }
        return ans.length();
    }
};