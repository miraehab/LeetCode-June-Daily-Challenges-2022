class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> ans;
        sort(products.begin(), products.end());
        int left = 0, right = products.size()-1;
        for(int i = 0; i < searchWord.length(); ++i){
            while(left <= right && products[left][i] != searchWord[i]) ++left;
            while(right >= left && products[right][i] != searchWord[i]) --right;
            vector<string> tmp;
            for(int j = left, cnt = 0; cnt < 3 && j <= right; ++cnt, ++j){
                tmp.push_back(products[j]);
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};