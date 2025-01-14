class Solution {
public:
   vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
    int n = A.size();
    vector<int> result(n, 0);
    unordered_set<int> seenA, seenB;
    int count = 0;

    for (int i = 0; i < n; ++i) {
        // Add current elements of A and B to their respective sets
        if (seenB.count(A[i])) {
            ++count;  // A[i] is already in seenB, so it's common
        }
        seenA.insert(A[i]);

        if (seenA.count(B[i])) {
            ++count;  // B[i] is already in seenA, so it's common
        }
        seenB.insert(B[i]);

        // Update the result for the current index
        result[i] = count;
    }

    return result;
}

};