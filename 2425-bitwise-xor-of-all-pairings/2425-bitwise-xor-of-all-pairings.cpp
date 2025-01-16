class Solution {
public:
    int xorAllNums(vector<int>& num1, vector<int>& num2) {
    int n = num1.size();
    int m = num2.size();
    unordered_map<int,long>mp;
    for(auto num : num1){
        mp[num] += m;
    }
     for(auto num : num2){
        mp[num] += n;
    }
    int result = 0;
    for(auto it : mp){
        int num = it.first;
        int freq = it.second;
        if(freq%2 == 1){
            result ^= num;
        }
       
    }
     return result;
}

};