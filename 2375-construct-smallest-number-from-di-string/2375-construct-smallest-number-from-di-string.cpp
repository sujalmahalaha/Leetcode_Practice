class Solution {
public:
    bool match(string &num , string &pattern){
        for(int i = 0 ; i<pattern.size();i++){
            if((pattern[i]=='I' && num[i]>num[i+1]) || (pattern[i]=='D' && num[i]<num[i+1])){
                return false;
            }
        }
        return true;
    }
    string smallestNumber(string pattern) {
        int n = pattern.size();
        string num = "";
        for(int i = 1 ; i<= n+1 ; i++){
            num.push_back(i+'0');
        }
        while(!match(num , pattern)){
            next_permutation(begin(num) , end(num));
        }
        return num;
        
    }
};