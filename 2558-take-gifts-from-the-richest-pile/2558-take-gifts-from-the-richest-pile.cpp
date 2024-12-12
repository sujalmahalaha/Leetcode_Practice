class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        sort(rbegin(gifts),rend(gifts));
        int count = 0;
        priority_queue<int >pq;
        for(auto it : gifts){
            pq.push(it);
        }
        while(k>=1){
            int top = pq.top();
            pq.pop();
            int squareRoot = (int)sqrt(top);
            pq.push(squareRoot);
            k--;
        }
        long long  sum = 0 ;
       while(!pq.empty()){
        sum += pq.top();
        pq.pop();
       }
        return sum ;
        
    }
};