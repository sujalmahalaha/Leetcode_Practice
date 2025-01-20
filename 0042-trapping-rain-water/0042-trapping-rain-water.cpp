class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int>leftMax(n , 0);
        vector<int>rightMax(n , 0);
        int store = 0;
        for(int i = 0 ; i< n ;i++){
            store = max(store , height[i]);
            leftMax[i] = store;
        }
        store = 0;
        for(int i = n-1 ; i>=0 ; i--){
            store = max(store , height[i]);
            rightMax[i] = store;
        }
        int sum = 0;
        for(int i = 0  ; i<n ; i++){
            sum += min(leftMax[i], rightMax[i])-height[i];
        }
        return sum;
        
    }
};