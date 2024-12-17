class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> count(26, 0); //S.C : O(26)
        for(char &ch : s) { //T.C : O(n)
            count[ch-'a']++;
        }

        string result;

        int i = 25; //start form last letter so that we can find the largest character first
        while(i >= 0) { //O(26)
            if(count[i] == 0) {
                i--;
                continue;
            }

            char ch  = 'a' + i; //you will get the character
            int freq = min(count[i], repeatLimit);

            result.append(freq, ch);
            count[i] -= freq;

            if(count[i] > 0) {
                //find next largest character
                int j = i-1;
                while(j >= 0 && count[j] == 0) { //O(26)
                    j--;
                }

                if(j < 0) {
                    break;
                }

                result.push_back('a' + j);
                count[j]--;
            }
        }

        return result;
    }
};