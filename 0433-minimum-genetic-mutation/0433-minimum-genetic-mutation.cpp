class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string>visited;
        unordered_set<string>banked(bank.begin() , bank.end());
        queue<string>q;
        q.push(startGene);
        int lebel = 0;
        while(!q.empty()){
            int n = q.size();
            while(n--){
                string curr = q.front();
                q.pop();
                if(curr == endGene){
                    return lebel;
                }
                for(auto ch : "ACGT"){
                  
                    for(int i = 0 ; i<curr.size() ; i++){
                        string neighbour = curr;
                        neighbour[i] = ch;
                        if(visited.find(neighbour) == visited.end() && banked.find(neighbour) != banked.end()){
                            visited.insert(neighbour);
                            q.push(neighbour);
                        }
                    }
                }

            }
            lebel++;
        }
        return -1;
        
    }
};