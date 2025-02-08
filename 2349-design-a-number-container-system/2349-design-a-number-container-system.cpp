class NumberContainers {
public:
unordered_map<int , int >IndexToNum;
unordered_map<int , set<int>>NumToIndex;
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if(IndexToNum.count(index)){
            int prev = IndexToNum[index];
            NumToIndex[prev].erase(index);
            if(NumToIndex[prev].empty()){
                NumToIndex.erase(prev);
            }
        }
        IndexToNum[index] = number;
        NumToIndex[number].insert(index);
        
    }
    
    int find(int number) {
        if(NumToIndex.count(number)){
            return *NumToIndex[number].begin();
        }
        return -1;
        
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */