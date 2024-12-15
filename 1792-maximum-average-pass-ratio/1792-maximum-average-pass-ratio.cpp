class Solution {
public:
   double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();

        vector<double> PR(n);
        for(int i = 0; i < n; i++) {
            double ratio = (double)classes[i][0]/classes[i][1];
            PR[i] = ratio;
        }

        while(extraStudents--) { //O(n)
            //student 0

            vector<double> updatedPR(n);
            for(int i = 0; i < n; i++) {
                double newRatio = (double)(classes[i][0]+1)/(classes[i][1]+1);
                updatedPR[i] = newRatio;
            }

            int bestClassIdx = 0;
            double bestDelta = 0;

            for(int i = 0; i < n; i++) { //O(n)
                double delta = updatedPR[i] - PR[i];
                if(delta > bestDelta) {
                    bestDelta = delta;
                    bestClassIdx = i;
                }
            }

            PR[bestClassIdx] = updatedPR[bestClassIdx];
            classes[bestClassIdx][0]++;
            classes[bestClassIdx][1]++;
        }

        double result = 0.0; //AR
        for(int i = 0; i < n; i++) {
            result += PR[i];
        }

        return result/n;
    }
};