class Solution {
public:
    int maximumLength(string s) {
        int n = s.size();
       vector<vector<int>>t(26 , vector<int>(n+1 , 0));
       char prev_char = s[0];
       int length = 0;
        for(int i = 0 ; i<n ; i++){
            char curr_char = s[i];
            if(curr_char == prev_char){
                length++;
                t[curr_char-'a'][length] +=1;

            }
            else{
                length = 1;
                t[curr_char -'a'][length] += 1;
                prev_char = curr_char;
            }
        }

        int result = -1;

        for(int i = 0 ; i<26; i++){
            int sum = 0;
            for(int j = n; j>=1 ; j--){
                sum += t[i][j];
                if(sum>=3){
                    
                    result = max(result , j);
                    break;
                }
            }
        }
        return result;
        
    }
};