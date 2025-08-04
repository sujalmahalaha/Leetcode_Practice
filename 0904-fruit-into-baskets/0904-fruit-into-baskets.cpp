class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int i = 0;
        int j = 0;
        map<int,int>mp;
        int result = 0;

        while(j<n){
          mp[fruits[j]]++;
          if(mp.size()<=2){
            result = max(result , j-i+1);
          }else{
            mp[fruits[i]]--;
            if(mp[fruits[i]]==0){
                mp.erase(fruits[i]);
            }
            i++;
          }
          j++;
        }
        return result;
        
    }
};