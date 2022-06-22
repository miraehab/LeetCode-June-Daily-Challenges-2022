class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> track_max;
        int i;
        for(i = 1; i < heights.size(); ++i){
            if(heights[i-1] >= heights[i]) continue;
            if(heights[i]-heights[i-1] <= bricks){
                bricks-=(heights[i]-heights[i-1]);
                track_max.push((heights[i]-heights[i-1]));
            }else if(ladders > 0){
                if(!track_max.empty() && (heights[i]-heights[i-1]) < track_max.top()){
                    bricks+=track_max.top() - (heights[i]-heights[i-1]);
                    track_max.pop();
                    track_max.push((heights[i]-heights[i-1]));
                }
                 --ladders;
            }
            else break;
        }
        return i - 1;
    }
};