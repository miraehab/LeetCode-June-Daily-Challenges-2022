class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        deque<int> possible;
        int sum = 0, maxi = INT_MIN, tmp = 1;
        for(int i = 0; i < k+1; ++i){
            if(i == 0){
                for(int j = 0; j < k; ++j){
                    sum+=cardPoints[j];
                    possible.push_front(cardPoints[j]);
                }
                maxi = sum;
            }else{
                sum-=possible.front();
                //cout<<"-"<<possible.front()<<endl;
                possible.pop_front();
                //cout<<"+"<<cardPoints[cardPoints.size()-tmp]<<endl;
                sum+=cardPoints[cardPoints.size()-tmp];
                ++tmp;
                maxi = max(maxi, sum);
            }
        }
        return maxi;
    }
};