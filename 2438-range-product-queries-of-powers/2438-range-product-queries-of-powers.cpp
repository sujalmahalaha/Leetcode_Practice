class Solution {
public:
int m = 1e9+7;
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int>result;
        vector<int>power;
        for(int i = 0 ; i< 32 ; i++){
            if((n&(1<<i)) != 0){
                power.push_back(1<<i);
            }
        }
        for(auto it : queries){
            int start = it[0];
            int end = it[1];
            long product = 1;
            for(int i = start ; i<=end ; i++){
                product =(product*power[i])%m;
            }
            result.push_back(product);
        }
        return result;
        
    }
};