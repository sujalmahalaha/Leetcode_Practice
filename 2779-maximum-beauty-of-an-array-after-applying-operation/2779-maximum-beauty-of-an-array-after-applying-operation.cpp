class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int n= nums.size();
        vector<pair<int, int>> intervals(n);
        for(int i = 0  ; i< n ; i++){
            intervals[i] = {nums[i]-k , nums[i]+k};

        }
        sort(begin(intervals), end(intervals));
        int maxBeauty = 0;
        deque<pair<int , int>>deq;
        for(auto it : intervals){
            while(!deq.empty() && deq.front().second<it.first){
                deq.pop_front();
            }
            deq.push_back(it);
            maxBeauty  = max(maxBeauty , (int)deq.size());
        }
        return maxBeauty;


    }
};