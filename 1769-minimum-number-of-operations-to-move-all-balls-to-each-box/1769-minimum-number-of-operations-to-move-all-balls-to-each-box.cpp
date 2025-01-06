class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n =  boxes.size();
        vector<int>answer(n,0);
        unordered_set<int>idx;
        for(int i = 0;i<n;i++) if(boxes[i]=='1') idx.insert(i);

        for(int i = 0;i<n;i++)
        {
            int moves = 0;
            for(auto &el:idx)
            {
                moves += abs(i-el);
            }
            answer[i] = moves;
        }
        return answer;

    }
};