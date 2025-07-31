class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int>result;
         unordered_set<int>prev;
          unordered_set<int>curr;
        for(int i = 0 ; i<arr.size() ; i++){
            for(int x : prev){
                curr.insert(x | arr[i]);
                result.insert(x|arr[i]);
            }
            curr.insert(arr[i]);
            result.insert(arr[i]);
            prev = curr;
            curr.clear();
        }
        return result.size();
    }
};