class Solution {
public:
   int t[20001][4];


    int helper(vector<int>&subarray , int count , int i , int k ){
        if(count == 0)return 0;
        if(i>=subarray.size())return INT_MIN;
        if(t[i][count] != -1)return t[i][count];
        int take = subarray[i] + helper(subarray , count-1 ,i+k , k);
        int notTake = helper(subarray , count , i+1 , k);
        return t[i][count] = max(take , notTake);
    }

    void solve(vector<int>&subarray , int count , int i , int k , vector<int>&result){
        memset(t , -1 , sizeof(t));
        if(count == 0)return ;
        if(i>=subarray.size())return;
        int take = subarray[i] + helper(subarray , count-1 ,i+k , k);
        int notTake = helper(subarray , count , i+1 , k);
        if(take>=notTake){
            result.push_back(i);
            solve(subarray , count-1 , i+k , k , result);
        }
        else{
            solve(subarray , count , i+1 , k , result);
        }
    }

    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        vector<int>subarray;
        int i = 0 ;
        int j = 0;
        int windowSum = 0;
        while(j<nums.size()){
            windowSum += nums[j];
            if(j-i+1==k){
                subarray.push_back(windowSum);
                windowSum -= nums[i];
                i++;
            }
            j++;
        }
        vector<int>result;
        solve(subarray , 3 , 0 , k , result);
        return result ;
    }
};