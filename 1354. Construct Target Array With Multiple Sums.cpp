class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<int> track_max;
        long long sum = 0;
        
        for(int i = 0; i < target.size(); ++i){
            track_max.push(target[i]);
            sum+=target[i];
        }
        
        while(track_max.top() > 1){
            int top = track_max.top();
            track_max.pop();
            sum-=top;
            if(top <= sum || sum < 1) return false;
            int x = top % sum;
            sum+=x;
            track_max.push(x? x:sum);
        }
        return true;
    }
};