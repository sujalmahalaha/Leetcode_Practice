class Solution {
public:
    string answerString(string word, int numFriends) {
        int n = word.size();
        int longestpossibleResult = n - (numFriends-1);
        string result ;
        for(int i = 0 ; i< n ; i++){
            int canTake = min(longestpossibleResult , n-i);
            result = max(result , word.substr(i , canTake));
        }
        return result;
        
    }
};