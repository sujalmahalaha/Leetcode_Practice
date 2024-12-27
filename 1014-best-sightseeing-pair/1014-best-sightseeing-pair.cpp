class Solution {
public:
    int solve(vector<int>& values , int i , int j , vector<vector<int>>&dp){
        if (j >= values.size()) return 0;
        if(dp[i][j] != -1){
            return dp[i][j];
        }

    int result = values[i] + values[j] + i - j;
   int  take = max( result ,  solve( values ,i , j+1,dp));
    int notTake = max(result , solve(values , i+1 , i+2,dp));
    return dp[i][j] = max(take , notTake);
    }
    int maxScoreSightseeingPair(vector<int>& values) {
        // int result = 0;
        // for(int i = 0 ; i<=values.size()-2 ; i++){
        //     for(int j = i+1 ; j<=values.size()-1; j++){
        //         int sum = values[i]+values[j]+i-j;
        //         result = max(sum , result);
        //     }
        // }
        // return result;
        int i = values.size()-1;
        vector<vector<int>>dp(i+1 , vector<int>(i+1 , -1));
        return solve(values , 0 , 1, dp);
        
    }
};